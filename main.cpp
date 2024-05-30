#include <iostream>
#include <string>

#include "Sales_data.h"

// extern 关键字
extern int test_var;

extern void f();

constexpr int get_size() {
    return 4;
}

int func() {
    return 5;
}

int& func2(int& i) {
    return i;
}

constexpr int size_arr = 10;

// 返回s中c第一次出现的位置索引
// occurs统计c出现的总次数
std::string::size_type find_char(
    const std::string& s,
    const char c,
    std::string::size_type& occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); i++) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            occurs++;
        }
    }
    return ret;
}

bool is_sentence(const std::string& s) {
    std::string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

// 引用返回左值
char& get_index(std::string& s, std::string::size_type idx) {
    return s[idx];
}

// 返回数组
// 数组不能被拷贝，因此不能返回数组，只能返回指针，但是数组可以作为形参
int* get_array(int arr[], int idx) {
    return arr;
}

// C++11尾置返回
auto end_ret(const int param) -> int {
    return param;
}

// 函数重载：const仅对指针(底层const)和引用能够重载
// 优先调用非const版本
inline const std::string& short_string(const std::string& a, const std::string& b) {
    return a.size() < b.size() ? a : b;
}

inline std::string& short_string(std::string& a, std::string& b) {
    auto& ret = short_string(const_cast<const std::string&>(a),
        const_cast<const std::string&>(b));
    return const_cast<std::string&>(ret);
}

void test1() {
    // 引用返回左值
    std::string s = "index";
    char& ch = get_index(s, 0); // OK (but why?)
    ch = 'a';
    std::cout << s << std::endl; // andex (ch ref get_index(s, 0))
    get_index(s, 0) = 'i'; // 返回引用类型，可以作为左值(Java函数返回值也可以作为左值)
}

using std::string;
using sz = string::size_type;


// constexpr函数
// 返回值和形参都是字面值类型
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

void test2() {
    const Sales_data s(std::cin);
    print(std::cout, s);
}

int main(int argc, char **argv) {
    // std::cout << ext_var << std::endl;
    // int y = 1, z = 3;
    // int& x = y; // 引用只能引一次，引用x永远是y的别名
    // x = z; // y = x = 3 （x并不是z的引用）
    // std::cout << "x = " << x << std::endl; // 3
    // std::cout << "y = " << y << std::endl; // 3
    // x = 2;
    // std::cout << "y = " << y << std::endl; // 2
    // std::cout << "z = " << z << std::endl; // 3 (x并不是z的引用)
    // int* pt = &x;
    // std::cout << sizeof pt << std::endl;
    // std::cout << sizeof x << std::endl;
    // int*& r = pt; // 指向指针的引用

    // int v1 = 3;
    // const int& v2 = v1;
    //
    // v1 = 4;
    // std::cout << v2 << std::endl;
    //
    // // 常量指针-> const的指针(顶层const)
    // double b = 0.1;
    // double* const con_ptr = &b; // const的指针，存储的地址值无法改变
    //
    // // 指向常量的指针(底层const)
    // // const只有指向常量的指针和常量引用能指向其
    // const int var = 1;
    // const int* con_ptr_var = &var; // 不能通过该指针改变对象的值
    // const int& con_ref_var = var;
    //
    // constexpr int size = get_size();
    // // constexpr int* p = &v1; // 错误, v1的地址值并不是const expression
    //
    // const int&x = 1; // 常量引用可以绑定到字面值，非常量引用则不行
    //
    // decltype(func()) sum = 10; // 将表达式func()的类型作为sum的类型
    // int& ref2 = v1;
    // decltype(ref2) ref3 = v1; // ref3是int&类型而不是int类型，这一处理与auto不同
    // auto var4 = ref2; // var4为int类型而不是int&类型
    //
    // std::string s1 = "50";
    // std::string& s2 = s1; // s2是s1的引用
    // s2[0] = '1';
    // std::cout << s2 << std::endl;
    // auto len = s1.size();
    // std::cout << sizeof len << std::endl;
    //
    // std::vector<int> vec1 = {1, 2, 3};
    // auto& vec2 = vec1;
    //
    // const std::vector<int> vec3 = {3, 4, 5}; // 不能修改vector中的元素
    // const std::vector<int> vec4 = {3, 4, 5};
    // // vec3 = vec4; // 也不能重新拷贝赋值
    // auto it = vec3.begin();
    //
    // int arr[10] = {1};
    // int* arr_ptr = arr; // 等价于 int* arr_ptr = &arr[0];
    // int (*ptr_arr)[10] = &arr; // 最好别这样用
    // // ptr_arr == arr_ptr 指向数组的指针和直接将数组转换为指针，该指针均指向数组的首元素
    // std::cout << ptr_arr << "  " << arr_ptr << std::endl;
    //
    // // auto 推导数组：推导类型为指针；而decltype推导数组的推导类型依旧为数组
    //
    // // 使用指针作为迭代器遍历数组
    // int arr2[size_arr] = {};
    // for (int* i = arr2, *j = &arr2[size_arr], cnt = 0; i != j; ++i, ++cnt) {
    //     *i = cnt;
    //     std::cout << *i << ' ';
    // }
    // std::cout << '\n';
    // for (int* beg = std::begin(arr2), *end = std::end(arr2); beg != end; ++beg) {
    //     std::cout << *beg << ' ';
    // }
    // std::cout << '\n';
    // // 使用迭代器遍历vec
    // std::vector<int> vv(10);
    // for (auto iter = vv.begin(), end = vv.end(); iter != end; ++iter) {
    //     std::cout << *iter << ' ';
    // }
    // std::cout << '\n';
    //
    // // cast
    // constexpr int ii = 1, jj = 2;
    // double slope = static_cast<double>(ii) / jj;
    //
    // // 右值引用
    // std::string&& ss =  "hello"; // hello是一个字面值（右值）,右值引用只能引用右值
    // const std::string& ss2 = "hello"; // 只有常量左值引用能引用右值
    // int&& rvalue_ref = 4;
    // int*&& rvalue_ref_v1 = &v1; // &v1是一个右值，而v1是一个左值
    //
    // int* ptr = &v1;
    // *ptr = 4; // *ptr 解引用运算符可以作为左值
    //
    // int param1 = 1;
    // int& ret1 = func2(param1);
    // ret1 = 5;
    // std::cout << param1 << "  " << ret1 << std::endl;
    //

    test2();
    return 0;
}
