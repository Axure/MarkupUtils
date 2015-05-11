//
// Created by 郑虎 on 15 年 五月. 10..
//

#ifndef MARKUPUTILS_SYNTAX_H
#define MARKUPUTILS_SYNTAX_H

#include <vector>
#include <map>

enum class Type {
    XML, HTML, JSX, MARKDOWN, BBCODE
};

class Syntax {
private:
    Type _type
    std::map<std::string, bool> _delimiters; // TODO: compare the performance of Map and Vector
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

    void add_delimiter(const std::string &delimiterName) {
        _delimiters[delimiterName] = true;
    }
};


#endif //MARKUPUTILS_SYNTAX_H


// TODO: an experimental mixed syntax