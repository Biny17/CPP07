#include "iter.hpp"
#include <iostream>

void p_one(char &c) {
    c += 1;
}

void print_char(const char &c) {
    std::cout << c;
}

void static_sum(const int &a)
{
    static int sum;

    sum += a;
    if (a == 0) {
        std::cout << sum << std::endl;
    }
}

void static_sum_add_one(int &a)
{
    static int sum;

    sum += a;
    if (a == 0) {
        std::cout << sum << std::endl;
    }
    a += 1;
}

int main(void) {
    char a[6] = "abcde";
    std::cout << a << std::endl;
    iter(a, 5, p_one);
    std::cout << a << std::endl;
    iter("Hello World !\n", 15, print_char);
    int b = 0;
    iter(&b, 1, static_sum_add_one);
    iter(&b, 1, static_sum_add_one);
    iter(&b, 1, static_sum_add_one);
    iter(&b, 1, static_sum_add_one);
    iter(&b, 1, static_sum_add_one);
    b = 0;
    iter(&b, 1, static_sum_add_one);
    b = 18;
    iter(&b, 1, static_sum);
    iter(&b, 1, static_sum);
    iter(&b, 1, static_sum);
    iter(&b, 1, static_sum);
    iter(&b, 1, static_sum);
    b = 0;
    iter(&b, 1, static_sum);
}