//
// Created by 郑虎 on 15 年 五月. 10..
//

#ifndef MARKUPUTILS_PARSER_H
#define MARKUPUTILS_PARSER_H

#include <string>
#include "Syntax.h"

class Parser {

private:
    Syntax _syntax;
    static void _parse(Syntax syntax, std::string input);
public:
    Parser(Syntax syntax);
    ~Parser();


};


#endif //MARKUPUTILS_PARSER_H
