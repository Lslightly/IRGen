#include <gtest/gtest.h>
#include <iostream>

#include "Constant.h"
#include "Function.h"
#include "Instruction.h"
#include "Module.h"
#include "Type.h"

using namespace SysYF::IR;

TEST(IRTest, UserRemoveOperands) {
    // https://github.com/ustc-compiler/IRGen/issues/2
    std::cout << "user remove operands";
    auto m = Module::create("test");
    auto fn = Function::create(FunctionType::create(Type::create(SysYF::IR::Type::VoidTyID, m), {}, m), "foo", m);
    auto bb = BasicBlock::create(m, "entry", fn);
    auto const_1 = ConstantInt::create(1, m);
    auto const_2 = ConstantInt::create(2, m);
    auto add = BinaryInst::create_add(const_1, const_2, bb, m);
    add->remove_operands(0, 0); // remove the first operand
    for (unsigned int i = 0; i < add->get_num_operand(); i++) {
        auto op = add->get_operand(i);
        ASSERT_EQ(op->get_use_list().front().arg_no_, i);
    }
}

