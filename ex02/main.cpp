#include "Array.hpp"
#include <iostream>

void print_array(Array<int> arr)
{
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_array(Array<char> arr)
{
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Array<int> a_int(10);
    int *a = new int();
    std::cout << *a << std::endl;
    delete a;
    for (unsigned int i = 0; i < a_int.size(); i++)
    {
        a_int[i] = i+5;
    }
    a_int[0] = 1;
    a_int[3] = 17;
    print_array(a_int);
    // Array<char> a_char(a_int);
    Array<int> cp (a_int);
    a_int[0] = 99;
    print_array(a_int);
    print_array(cp);
    cp = a_int;
    print_array(cp);
    Array<int> c (2);
    c = cp;
    c[5] = 8;
    print_array(c);
    try {
        c[12] = 1;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}