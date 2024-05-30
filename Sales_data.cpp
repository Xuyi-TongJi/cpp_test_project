//
// Created by 许逸 on 24-5-27.
//

#include "Sales_data.h"


Sales_data & Sales_data::combine(const Sales_data & rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}

double Sales_data::avg_privce() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    return 0;
}

void Sales_data::set_currrent_mode(const std::string &s) {
    current_mode = s;
}

Sales_data::Sales_data(std::istream & is) {
    // 对this解引用得到对当前对象的引用
    read(is, *this);
}

Sales_data add(const Sales_data & lhs, const Sales_data & rhs) {
    return Sales_data(lhs.isbn(), lhs.units_sold + rhs.units_sold, lhs.revenue + rhs.revenue);
}

std::ostream & print(std::ostream & os, const Sales_data & lhs) {
    os << lhs.isbn() << std::endl;
    return os;
}

std::istream & read(std::istream & is, Sales_data & lhs) {
    std::string bookNo;
    unsigned n = 0;
    double p = 0.0;
    is >> bookNo >> n >> p;
    lhs.set_isbn(bookNo);
    lhs.set_revenue(p * n);
    lhs.set_units_sold(n);
    return is;
}
