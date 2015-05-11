//
// Created by 郑虎 on 15 年 五月. 11..
//

#include "Node.hpp"

Node::Node(std::string inString, Syntax syntax, Tag tag) {

//    this->_tagName = Tag(inString, "");
    this->_set_tagName(tag);
    switch (syntax.get_type()) {
        case Type::HTML:
        // @Algorithm: Find the first tag, find its matching. If finished, exit. Ignoring contents before and after. This is the most efficient and neat way.
        // For HTML, there is one <.*> more than XML, because tags don't need to be closed. But some should be closed... We should be able to throw errors in this case.

            break;
        case Type::XML:

            std::map<int, Tag> occurrences; // @Note: Actually the matching should be dynamic... For XML.
            // There should only be two one pattern for XML, the <*> </*> way

            for(auto const &it : syntax.get_tags()) {
                // Find the tag is not that simple, because it is XML
            }


            break;
        case Type::JSX:
            break;
        case Type::MARKDOWN:
            // For markdown, there may be static matching...
            // We should first implement a working version, instead of optimizing the speed.
            std::size_t __minIndex = inString.length() + 1;
            std::string __minTag;
            for(auto const &it : syntax.get_tags()) {
                // @Problem: A general matching problem, to find the first occurrence of strings within a list.
                // I think the fastest way should be to go through the string, instead of doing some rash matchings.
                // We should build an index, or prefix tree for the tags...
                // TODO: rewrite with trie.
                if (inString.find(it.first.get_leftTag()) != std::string::npos) {
                    if (__minIndex > inString.find(it.first.get_leftTag())) {
                        __minIndex = inString.find(it.first.get_leftTag());
                        __minTag = it.first.get_leftTag(); // WOW, overloaed operator...
                    }
                }



            }
            // @Algorithm: Maybe we should make a virtual parent before parsing it... But adding a virtual tag to every syntax seems too extravagant.
            // @Algorithm: We should suppose that the things thrown in are all with a tag... The tag name is injected from its father...
            // @Algorithm: The thing between __minIndex and its start all belong to it...
            this->_add_property("content", inString.substr(0, __minIndex));



        break;

        case Type::BBCODE:

            break;
    }

}

std::string Node::self_to_string() { // TODO: report to JetBrains, that CLion would do wrong with same named functions, while clang does not.

    std::string __result;
    __result += this->_tagName.get_leftTag();
    for(auto const &it : this->_contents) {
        __result += to_string(it);
    }

    __result += this->_tagName.get_rightTag();

    return __result;

}

std::string Node::to_string(boost::any content) {
//    if (__result = is_string(content)) {
    if (is_string(content)) {
        return boost::any_cast<std::string>(content);
    } else { // @Case: it is a node
        return to_string(boost::any_cast<Node>(content));
    }
}

std::string Node::to_string(Node node) {
    return node.self_to_string();
}