#include "SysYBuilder.hpp"

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

void SysYBuilder::visit(SyntaxTree::Assembly &node) {
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

void SysYBuilder::visit(SyntaxTree::InitVal &node) {}

void SysYBuilder::visit(SyntaxTree::FuncDef &node) {}

void SysYBuilder::visit(SyntaxTree::FuncFParamList &node) {}

void SysYBuilder::visit(SyntaxTree::FuncParam &node) {}

void SysYBuilder::visit(SyntaxTree::VarDef &node) {}

void SysYBuilder::visit(SyntaxTree::LVal &node) {}

void SysYBuilder::visit(SyntaxTree::AssignStmt &node) {}

void SysYBuilder::visit(SyntaxTree::Literal &node) {}

void SysYBuilder::visit(SyntaxTree::ReturnStmt &node) {}

void SysYBuilder::visit(SyntaxTree::BlockStmt &node) {}

void SysYBuilder::visit(SyntaxTree::EmptyStmt &node) {}

void SysYBuilder::visit(SyntaxTree::ExprStmt &node) {}

void SysYBuilder::visit(SyntaxTree::UnaryCondExpr &node) {}

void SysYBuilder::visit(SyntaxTree::BinaryCondExpr &node) {}

void SysYBuilder::visit(SyntaxTree::BinaryExpr &node) {}

void SysYBuilder::visit(SyntaxTree::UnaryExpr &node) {}

void SysYBuilder::visit(SyntaxTree::FuncCallStmt &node) {}

void SysYBuilder::visit(SyntaxTree::IfStmt &node) {}

void SysYBuilder::visit(SyntaxTree::WhileStmt &node) {}

void SysYBuilder::visit(SyntaxTree::BreakStmt &node) {}

void SysYBuilder::visit(SyntaxTree::ContinueStmt &node) {}
