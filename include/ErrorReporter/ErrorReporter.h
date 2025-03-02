#ifndef _SYSYF_ERROR_REPORTER_H_
#define _SYSYF_ERROR_REPORTER_H_

#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>
#include "SyntaxTree.h"

namespace SysYF
{
class ErrorReporter
{
public:
    using Position = SyntaxTree::Position;
    explicit ErrorReporter(std::ostream &error_stream);

    void error(Position pos, const std::string &msg);
    void warn(Position pos, const std::string &msg);

protected:
    virtual void report(Position pos, const std::string &msg, const std::string &prefix);

private:
    std::ostream &err;
};

}
#endif  // _SYSYF_ERROR_REPORTER_H_
