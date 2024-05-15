//
// Created by 许逸 on 24-5-15.
//

#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>
#include <iostream>


class Sales_item {
    unsigned sold = 0;
    double revenue = 0.0;
    std::string isbn;
public:
    Sales_item() = default;
    explicit Sales_item(std::string  _isbn) : isbn(std::move(_isbn)) {}
    [[nodiscard]] double avg_price() const;
    [[nodiscard]] bool same_isbn(const Sales_item& rhs) const { return isbn == rhs.isbn; }
    // 运算符重载
    Sales_item& operator+= (const Sales_item&);
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, Sales_item&);
    friend Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs);
    // getter
    [[nodiscard]] unsigned get_sold() const { return sold; }
    [[nodiscard]] std::string get_isbn() const { return isbn; }
    [[nodiscard]] double get_revenue() const { return revenue; }
};

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

#endif //SALES_ITEM_H
