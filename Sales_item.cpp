//
// Created by 许逸 on 24-5-15.
//

#include "Sales_item.h"
#include <iostream>

inline double Sales_item::avg_price() const {
    if (sold > 0) {
        return revenue / sold;
    }
    return 0.0;
}

inline Sales_item& Sales_item::operator+=(const Sales_item& rhs) {
    sold += rhs.sold;
    revenue += rhs.revenue;
    return *this;
}

inline std::istream& operator>>(std::istream& is, Sales_item& sales) {
    double price = 0;
    is >> sales.isbn >> sales.sold >> price;
    if (is) {
        sales.revenue = sales.sold * price;
    } else {
        sales = Sales_item();
    }
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Sales_item& sales) {
    os << "SOLD: " << sales.get_sold() << "\nREVENUE: " << sales.get_revenue() << "\nISBN: " << sales.get_isbn() << '\n';
    return os;
}

inline Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
    if (lhs.get_isbn() == rhs.get_isbn()) {
        auto ret = Sales_item();
        ret.sold = lhs.sold + rhs.sold;
        ret.revenue = lhs.revenue + rhs.revenue;
        ret.isbn = lhs.isbn;
        return ret;
    }
    return {};
}