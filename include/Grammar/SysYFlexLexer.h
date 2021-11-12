#ifndef _SYSY_FLEX_LEXER_H_
#define _SYSY_FLEX_LEXER_H_

#ifndef YY_DECL
#define YY_DECL                                                         \
    yy::SysYParser::symbol_type SysYFlexLexer::yylex(SysYDriver& driver)
#endif

// We need this for yyFlexLexer. If we don't #undef yyFlexLexer, the
// preprocessor chokes on the line `#define yyFlexLexer yyFlexLexer`
// in `FlexLexer.h`:
#undef yyFlexLexer
#include <FlexLexer.h>

// We need this for the yy::SysYParser::symbol_type:
#include "SysYParser.h"

// We need this for the yy::location type:
#include "location.hh"

class SysYFlexLexer : public yyFlexLexer {
public:
    // Use the superclass's constructor:
    using yyFlexLexer::yyFlexLexer;

    // Provide the interface to `yylex`; `flex` will emit the
    // definition into `SysYScanner.cpp`:
    yy::SysYParser::symbol_type yylex(SysYDriver& driver);

    // This seems like a reasonable place to put the location object
    // rather than it being static (in the sense of having internal
    // linkage at translation unit scope, not in the sense of being a
    // class variable):
    yy::location loc;
};

#endif // _SYSY_FLEX_LEXER_H_
