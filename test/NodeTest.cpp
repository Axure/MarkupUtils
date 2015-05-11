//
// Created by 郑虎 on 15 年 五月. 11..
//

/*
 * @Thoughts: Where should the type be placed?
 * Is it an attribute of Syntax or Parser?
 * I think parser should be type free.. Only the syntax has types.
 * Actually this is what I am doing... I am just trying to get the type from the syntax.
 */

#include "../Node.hpp"
#include "../Syntax.h"

#include <iostream>

int main() {
    Syntax mySyntax;
    mySyntax.set_type(Type::HTML);
    mySyntax.add_tag("<div>", "</div>");
    mySyntax.add_tag("<a>", "</a>");

    Node myNode = Node("<div>ff</div>", mySyntax);
    std::cout << myNode.self_to_string() << std::endl;

}