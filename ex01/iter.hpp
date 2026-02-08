#pragma once

#include <stddef.h>

template<typename T>
void iter(T *arr, const size_t length, void (*fun)(T&))
{
    for (size_t i = 0; i < length; i++)
        fun(arr[i]);
}

template<typename T>
void iter(T *arr, const size_t length, void (*fun)(const T&))
{
    for (size_t i = 0; i < length; i++)
        fun(arr[i]);
}