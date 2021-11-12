add_library(
    Driver STATIC
    SysYDriver.cpp   
)

add_library(
    Scanner STATIC
    SysYScanner.cpp
)

add_library(
    Parser STATIC
    SysYParser.cpp
)

target_link_libraries(
    Driver
    Scanner
    Parser
    ASTLib
)
