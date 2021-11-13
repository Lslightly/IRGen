#include "SysYFBuilder.hpp"

#define CONST_INT(num) ConstantInt::get(num, module.get())
#define CONST_FLOAT(num) ConstantFloat::get(num, module.get())

// You can define global variables and functions here
// to store state

// store temporary value
Value *tmp_val = nullptr;

// types
Type *VOID_T;
Type *INT1_T;
Type *INT32_T;
Type *FLOAT_T;
Type *INT32PTR_T;
Type *FLOATPTR_T;

void SysYFBuilder::visit(SyntaxTree::Assembly &node) {
    VOID_T = Type::get_void_type(module.get());
    INT1_T = Type::get_int1_type(module.get());
    INT32_T = Type::get_int32_type(module.get());
    FLOAT_T = Type::get_float_type(module.get());
    INT32PTR_T = Type::get_int32_ptr_type(module.get());
    FLOATPTR_T = Type::get_float_ptr_type(module.get());
    for (const auto &def : node.global_defs) {
        def->accept(*this);
    }
}

// You need to fill them

void SysYFBuilder::visit(SyntaxTree::InitVal &node) {}

void SysYFBuilder::visit(SyntaxTree::FuncDef &node) {}

void SysYFBuilder::visit(SyntaxTree::FuncFParamList &node) {}

void SysYFBuilder::visit(SyntaxTree::FuncParam &node) {}

void SysYFBuilder::visit(SyntaxTree::VarDef &node) {}

void SysYFBuilder::visit(SyntaxTree::LVal &node) {}

void SysYFBuilder::visit(SyntaxTree::AssignStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::Literal &node) {}

void SysYFBuilder::visit(SyntaxTree::ReturnStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::BlockStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::EmptyStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::ExprStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::UnaryCondExpr &node) {}

void SysYFBuilder::visit(SyntaxTree::BinaryCondExpr &node) {}

void SysYFBuilder::visit(SyntaxTree::BinaryExpr &node) {}

void SysYFBuilder::visit(SyntaxTree::UnaryExpr &node) {}

void SysYFBuilder::visit(SyntaxTree::FuncCallStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::IfStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::WhileStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::BreakStmt &node) {}

void SysYFBuilder::visit(SyntaxTree::ContinueStmt &node) {}
