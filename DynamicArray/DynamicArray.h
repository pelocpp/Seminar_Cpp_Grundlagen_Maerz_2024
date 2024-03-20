// ===========================================================================
// DynamicArray.h
// ===========================================================================

#pragma once

#include <iostream>

class DynamicArray
{
private:
    size_t m_size;
    int* m_data;

public:
    // c'tor(s) / d'tor
    DynamicArray();
    DynamicArray(size_t size);

    // copy - c'tor
    DynamicArray(const DynamicArray& other);

    ~DynamicArray();

    // getter / setter
    size_t size() const;
    int& at(size_t index);

    // public interface
    void fill(int value);
    void resize(size_t newSize);
    void release();
    void print();

    // assignment operator
    DynamicArray& operator= (const DynamicArray& other);

    int& operator[] (size_t index);

    // comparison operators
    friend bool operator== (const DynamicArray& left, DynamicArray right);
    friend bool operator!= (const DynamicArray& left, DynamicArray right);
};

// ===========================================================================
// End-of-File
// ===========================================================================
