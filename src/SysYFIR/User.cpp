#include "User.h"
#include "internal_types.h"
#include <memory>
#include <vector>
#ifdef DEBUG
#include <cassert>
#endif

namespace SysYF
{
namespace IR
{
User::User(Ptr<Type> ty, const std::string &name , unsigned num_ops)
    : Value(ty, name)
{
    // if (num_ops_ > 0)
    //   operands_.reset(new std::list<Ptr<Value> >());
    operands_.resize(num_ops);
}

Ptr<Value> User::get_operand(unsigned i) const
{
    return operands_[i].lock();
}

void User::set_operand(unsigned i, Ptr<Value> v)
{
#ifdef DEBUG
    assert(i < num_ops_ && "set_operand out of index");
#endif
    // assert(operands_[i] == nullptr && "ith operand is not null");
    operands_[i] = v;  
    v->add_use(shared_from_this(), i);
}

void User::add_operand(Ptr<Value> v)
{
    operands_.push_back(v);  
    v->add_use(shared_from_this(), operands_.size()-1);
}

unsigned User::get_num_operand() const
{
    return operands_.size();
}

void User::remove_use_of_ops()
{
    for (auto op : operands_) {
        op.lock()->remove_use(shared_from_this());
    }
}

void User::remove_operands(int index1, int index2) {
    auto backup = std::vector<std::weak_ptr<Value>>{};
    for (auto iter = operands_.cbegin() + index2 + 1; iter != operands_.cend(); iter++) {
        backup.push_back(*iter);
    }
    for (auto iter = operands_.cbegin() + index1; iter != operands_.cend(); iter++) {
        iter->lock()->remove_use(shared_from_this());
    }
    operands_.erase(operands_.begin()+index1, operands_.end());
    for (auto op: backup) {
        add_operand(op.lock());
    }
    // std::cout<<operands_.size()<<std::endl;
}

}
}
