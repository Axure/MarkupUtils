//
// Created by 郑虎 on 15 年 五月. 11..
//

#include "Node.hpp"

Node::Node(std::string inString, Syntax syntax) {

//    this->_tagName = Tag(inString, "");
//    this->_set_tagName(Tag(inString, ""));
}

std::string Node::to_string() {

    std::string __result;
    __result += this->_tagName.get_leftTag().;
    for(auto const &it : Node::_contents) {
        __result += to_string(it);
    }

    __result += this->_tagName.get_rightTag();

    return __result;

}

std::string Node::to_string(boost::any content) {
    std::string __result;
//    if (__result = is_string(content)) {
    if (true) {
        return __result;
    } else { // @Case: it is a node
        return to_string(boost::any_cast<Node>(content));
    }
}

std::string Node::to_string(Node node) {
    return node.to_string();
}