//
// Created by 郑虎 on 15 年 五月. 11..
//

#ifndef MARKUPUTILS_NODE_H
#define MARKUPUTILS_NODE_H


#include <string>
#include <map>
#include "Syntax.h"
#include <boost/any.hpp>

/*
 * @Concern: We may only need Node. We do not need Tree. Because Trees are essentially Nodes.
 */

class Node {
/*
 * @Description: This is a class for DOM-node-like thing
 */
private:
    Type _type;
    Tag _tagName; // @Note: This is not a XML specific library, so we won't omit the < > automatically
    std::map<std::string, std::string> _properties;
    std::map<int, boost::any> _contents;
    // @Thoughts: Maybe I need to use Boost.Any here.

    const std::string &_get_left_tagName() const {
        return _tagName.get_leftTag();
    }

    const std::string &_get_right_tagName() const {
        return _tagName.get_rightTag();
    }

    void _set_tagName(Tag &_tagName) {
        Node::_tagName = _tagName;
    }

    void _add_property(const std::string &_propertyName, const std::string &_propertyContent) {
        Node::_properties[_propertyName] = _propertyContent;
    }

    std::string &is_string(const boost::any & operand) // @Thoughts: Where should I append such code to?
    {
        return boost::any_cast<std::string>(&operand);
//        return true;
    }


public:

    Node(std::string inString, Syntax syntax);
    std::string to_string();
    std::string to_string(Node node);
    std::string to_string(boost::any content);



};


#endif //MARKUPUTILS_NODE_H
