//
// Created by 郑虎 on 15 年 五月. 10..
//

#include "Parser.h"
#include <boost/regex.hpp>

Parser::Parser(Syntax syntax) {
    _syntax = syntax;
}

void Parser::_parse(Syntax syntax, std::string input) {

    switch (syntax.get_type()) {
        case Type::HTML:



            break;
        case Type::XML:
            break;
        case Type::JSX:
            break;
        case Type::MARKDOWN:
            break;
        case Type::BBCODE:
            break;


    }
}