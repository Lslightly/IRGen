#include "SysYBuilder.hpp"

#define CONST_INT(num) ConstantInt::get(num, module.get())
#define CONST_FLOAT(num) ConstantFloat::get(num, module.get())

// You can define global variables here
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

void SysYBuilder::visit(SyntaxTree::InitVal &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::FuncDef &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::FuncFParamList &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::FuncParam &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::VarDef &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::AssignStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::LVal &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::Literal &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::ReturnStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::BlockStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::EmptyStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::ExprStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::UnaryCondExpr &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::BinaryCondExpr &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::BinaryExpr &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::UnaryExpr &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::FuncCallStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::IfStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::WhileStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::BreakStmt &node) {
    return;
}

void SysYBuilder::visit(SyntaxTree::ContinueStmt &node) {
    return;
}
