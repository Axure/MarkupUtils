//
// Created by 郑虎 on 15 年 五月. 11..
//

#ifndef MARKUPUTILS_NODE_H
#define MARKUPUTILS_NODE_H


#include <string>
#include <map>
#include "Syntax.h"

/*
 * @Concern: We may only need Node. We do not need Tree. Because Trees are essentially Nodes.
 */

class Node {
/*
 * @Description: This is a class for DOM-node-like thing
 */
private:
    std::string _tagName; // @Note: This is not a XML specific library, so we won't omit the < > automatically
    std::map<std::string, std::string> _properties;


    const std::string &_get_tagName() const {
        return _tagName;
    }

    void _set_tagName(const std::string &_tagName) {
        Node::_tagName = _tagName;
    }

    void _add_property(const std::string &_propertyName, const std::string &_propertyContent) {
        Node::_properties[_propertyName] = _propertyContent;
    }

public:

    Node(std::string inString, Syntax syntax);




};


#endif //MARKUPUTILS_NODE_H
