//
// Created by 郑虎 on 15 年 五月. 10..
//

#ifndef MARKUPUTILS_SYNTAX_H
#define MARKUPUTILS_SYNTAX_H

#include <vector>
#include <map>
#include <string>

enum class Type {
    XML, HTML, JSX, MARKDOWN, BBCODE
};

class Tag {
private:
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

    Tag(const std::string &leftTag, const std::string &rightTag) {
        this->_leftTag = leftTag;
        this->_rightTag = rightTag;
    }
};

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

    void add_delimiter(const std::string &leftDelimiter, const std::string &rightDelimiter) {
        Tag __tag = Tag(leftDelimiter, rightDelimiter);
        _tags[__tag] = true;

    }
};


#endif //MARKUPUTILS_SYNTAX_H


// TODO: an experimental mixed syntax