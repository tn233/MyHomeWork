#ifndef HEADER_H//ifndef指的是当且仅当变量未定义未真，ifdef指的是当且仅当变量已定义时为真（使用这些功能可以有效防止重复包含的发生）
#define HEADER_H//定义
#include <iostream>
#include <string>
struct bingo {
    std::string name;
};
#endif//结束判断，对ifndef和ifdef都有效