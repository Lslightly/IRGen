#include "SysYDriver.h"
// #include "SysYParser.h"

SysYDriver::SysYDriver()
    : trace_scanning(false), trace_parsing(false)
{
}

SysYDriver::~SysYDriver()
{
}

SyntaxTree::Node* SysYDriver::parse(const std::string &f)
{
    file = f;

    // lexer begin
    scan_begin();
    yy::SysYParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // parser begin
    parser.parse();
    // lexer end
    scan_end();

    return this->root;
}

void SysYDriver::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void SysYDriver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}


void SysYDriver::scan_begin()
{
    lexer.set_debug(trace_scanning);

    // Try to open the file:
    instream.open(file);

    if(instream.good()) {
        lexer.switch_streams(&instream, 0);
    }
    else if(file == "-") {
        lexer.switch_streams(&std::cin, 0);
    }
    else {
        error("Cannot open file '" + file + "'.");
        exit(EXIT_FAILURE);
    }
}

void SysYDriver::scan_end()
{
    instream.close();
}
