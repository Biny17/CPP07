#pragma once

#include <exception>

template <typename T>
class Array
{
private:
    T* elems;
    unsigned int len;
    template<typename U>
    Array(const Array<U>& other);

    template<typename U>
    Array& operator=(const Array<U>& other);

public:
    class OutOfRange: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "index out of range !";
        }
    };
    ~Array() {
        delete[] elems;
    }

    Array() : len(0), elems(0) {}

    Array(unsigned int n)
    : len(n) {
        elems = new T[len];
    }

    Array(const Array &other)
    : len(other.size())
    {
        elems = new T[len];
        for (unsigned int i = 0; i < len; i++)
            elems[i] = other.elems[i];
    }
    Array& operator=(const Array &rhs)
    {
        delete[] elems;
        len = rhs.len;
        elems = new T[len];
        for (unsigned int i = 0; i < len; i++)
            elems[i] = rhs.elems[i];
        return *this;
    }
    T& operator[](unsigned int i)
    {
        if (i >= len) {
            throw OutOfRange();
        } else {
            return *(elems+i);
        }
    }
    unsigned int size() const
    {
        return len;
    }
};
