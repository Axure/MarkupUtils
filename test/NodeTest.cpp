//
// Created by 郑虎 on 15 年 五月. 11..
//

#include "../Node.hpp"
#include "../Syntax.h"

#include <iostream>

int main() {
    Syntax mySyntax;
    mySyntax.add_delimiter("<div>");
    mySyntax.add_delimiter("<a>");

    Node myNode = Node("<div>ff</div>", mySyntax);


}