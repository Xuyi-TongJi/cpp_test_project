//
// Created by 许逸 on 24-5-27.
//

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
    // 声明友元->add函数是Sales_data的友元，可以访问其中所有元素
    // 友元并非函数的声明，仅仅只是影响访问权限
    friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    // 在类内实现的函数默认是inline的
    // const函数->this是一个指向常量的指针->不能改变调用它的对象的内容（成员变量）
    [[nodiscard]] constexpr std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
    [[nodiscard]] double avg_privce() const;

    /**
     * current_mode
     * 静态成员
     * 静态成员函数不能声明为const
     */
    static std::string current_mode;

    static constexpr int version = 1;

    static void set_currrent_mode(const std::string& s);

    // setter
    void set_isbn(const std::string& s) { this->bookNo = s; }
    void set_units_sold(const unsigned n) { this->units_sold = n; }
    void set_revenue(const double r) { this->revenue = r; }

    // 默认构造函数（类内默认inline）
    Sales_data() = default;

    // explicit 抑制隐式类型转换
    explicit Sales_data(std::string s): bookNo(std::move(s)) {} // 使用转发代替赋值 ? 只有一个参数的构造函数用explicit关键字修饰

    Sales_data(std::string s, const unsigned n, const double p): bookNo(std::move(s)), units_sold(n), revenue(p * n) {}

    explicit Sales_data(std::istream&);

    // 委托构造函数
    Sales_data(const std::string &s, const unsigned n) : Sales_data(s, n, 0) {}

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


#endif //SALES_DATA_H
