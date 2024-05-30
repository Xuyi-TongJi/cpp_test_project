//
// Created by 许逸 on 24-5-15.
//

#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>


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

#endif //SALES_ITEM_H
