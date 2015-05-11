//
// Created by 郑虎 on 15 年 五月. 10..
//

#ifndef MARKUPUTILS_SYNTAX_H
#define MARKUPUTILS_SYNTAX_H

#include <vector>
#include <map>
#include <string>
#include <boost/regex.hpp>

enum class Type {
    XML, HTML, JSX, MARKDOWN, BBCODE
};

enum class TagType {
    Single, Double,
};

class Tag {
private:
    TagType _tagType;
    std::string _leftTag, _rightTag;

public:

    const std::string &get_leftTag() const {
        return _leftTag;
    }

    const std::string &get_rightTag() const {
        return _rightTag;
    }

    Tag() {

    };

    // The tag should be a regexp instead of a string.
    // The property patterns are provided in the regexp.
    Tag(const std::string &leftTag) {
        this->_tagType = TagType::Single;
        this->_leftTag = leftTag;
    }

    Tag(const std::string &leftTag, const std::string &rightTag) {
        this->_tagType = TagType::Double;
        this->_leftTag = leftTag;
        this->_rightTag = rightTag;
    }

    // @Solution: http://stackoverflow.com/questions/30168553/invalid-operands-to-binary-expression-when-using-custom-struct-as-index-of-map
    bool operator< (const Tag& rhs) const
    {
        return this->_leftTag < rhs._rightTag ||
               (this->_leftTag == rhs._leftTag && this->_rightTag < rhs._rightTag);
    }
};

//struct Tag {
//    std::string left_tag, right_tag;
//};

class Syntax {
private:
    Type _type;
    std::map<Tag, bool> _tags; // TODO: compare the performance of Map and Vector
    // @Note: force it to use SBT.
public:
    Syntax() {

    };

    virtual ~Syntax();

    const Type &get_type() const {
        return _type;
    }

    void set_type(const Type &_type) {
        Syntax::_type = _type;
    }

    void add_tag(const std::string &leftDelimiter, const std::string &rightDelimiter) {
        Tag __tag = Tag(leftDelimiter, rightDelimiter);
//        Tag __tag;
//        __tag.left_tag = leftDelimiter;
//        __tag.right_tag = rightDelimiter;
        this->_tags[__tag] = true;

    }


    const std::map<Tag, bool> &get_tags() const {
        return _tags;
    }

    void build_trie();
};


#endif //MARKUPUTILS_SYNTAX_H


// TODO: an experimental mixed syntax