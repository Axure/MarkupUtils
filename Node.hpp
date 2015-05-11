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
    Type _type; // This is not more important.
    Tag _tagName; // @Note: This is not a XML specific library, so we won't omit the < > automatically
    std::map<std::string, std::string> _properties;
    std::map<int, boost::any> _contents; // @Description: the innerHTML-like thing.


    // @Thoughts: Maybe I need to use Boost.Any here.
    void _set_tagName(Tag tagName) {
        this->_tagName = tagName;
    }

    void _add_property(const std::string &_propertyName, const std::string &_propertyContent) {
        Node::_properties[_propertyName] = _propertyContent;
    }

//    const std::string &is_string(const boost::any & operand) // @Thoughts: Where should I append such code to?
    bool is_string(const boost::any & operand)
    {
        return boost::any_cast<std::string>(&operand);
//        return true;
    }



public:

    Node(std::string inString, Syntax syntax, Tag tag);
    std::string self_to_string();
    std::string to_string(Node node);
    std::string to_string(boost::any content);



};


#endif //MARKUPUTILS_NODE_H
