//
// Created by 许逸 on 24-5-28.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    // 在public中定义别名，用户可以使用pos
    using pos = std::string::size_type;

    // constructor
    Screen() = default;
    Screen(const pos ht, const pos wd, const char c) : height(ht), width(wd), contents(ht * wd, c) {}

    // 读取光标处的字符
    // const成员函数->将this指针定义为一个指向const的指针(底层const)
    // 常量对象只能调用const成员函数
    [[nodiscard]] char get() const { return contents[cursor]; }
    [[nodiscard]] inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    mutable size_t access_ctr = 0; // mutable关键字，即使在const成员函数内，也能被修改
};




#endif //SCREEN_H
