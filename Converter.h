//
// Created by 郑虎 on 15 年 五月. 10..
//

#ifndef MARKUPUTILS_CONVERTER_H
#define MARKUPUTILS_CONVERTER_H

#include <map>

class Converter {

private:
    std::map<std::string, std::string> _relationBetweenDelimiter;

public:
    Converter();
    virtual ~Converter();


};


#endif //MARKUPUTILS_CONVERTER_H
