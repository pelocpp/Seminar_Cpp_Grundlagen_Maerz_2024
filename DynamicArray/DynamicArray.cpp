// ===========================================================================
// DynamicArray.cpp
// ===========================================================================

#include <string>
#include <stdexcept>

#include "DynamicArray.h"

// c'tor(s) / d'tor
DynamicArray::DynamicArray()
{
    m_size = 0;
    m_data = nullptr;
}

DynamicArray::DynamicArray(size_t size)
{
    m_size = size;
    m_data = new int[size];

    // initialize buffer with default values
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = 0;
    }
}

DynamicArray::~DynamicArray()
{
    delete[] m_data;
}

// getter / setter
size_t DynamicArray::size() const
{
    return m_size;
}

// fast and performant - but may crash
int& DynamicArray::operator[](size_t index)
{
    // no bounds checking - intentionally !!!
    return m_data[index];
}

// less fast - but safe - exception handling
int& DynamicArray::at(size_t index)
{
    // bounds checking
    if (index >= m_size) {

        std::string msg = "Wrong Index: " + std::to_string(index);
        throw std::out_of_range(msg);
    }

    return m_data[index];
}

// public interface
void DynamicArray::fill(int value)
{
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}

void DynamicArray::resize(size_t newSize)
{
    // allocate new buffer
    int* data = new int[newSize];

    size_t minSize = (newSize <= m_size) ? newSize : m_size;

    // copy old buffer into new one
    for (size_t i = 0; i < minSize; ++i) {
        data[i] = m_data[i];
    }

    // initialize rest of buffer, if any, with default values
    for (size_t i = m_size; i < newSize; ++i) {
        data[i] = 0;
    }

    // release old buffer
    delete[] m_data;

    // switch to new buffer
    m_size = newSize;
    m_data = data;
}

void DynamicArray::release() {

    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

void DynamicArray::print()
{
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << '\n';
    }
    std::cout << "[Length: " << m_size << ']' << std::endl;
}

// copy - c'tor
DynamicArray::DynamicArray(const DynamicArray& other)
{
    // create new buffer
    m_data = new int[other.m_size];

    // copy right side buffer to current buffer
    for (int i = 0; i < other.m_size; i++) {
        m_data[i] = other.m_data[i];
    }

    m_size = other.m_size;
}

// assignment operator
DynamicArray& DynamicArray::operator = (const DynamicArray& other)
{
    if (this != &other) {

        // release old, left side
        delete[] m_data;

        // create new buffer
        int* tmp = new int[other.m_size];

        // copy right side buffer to left side buffer
        for (int i = 0; i < other.m_size; i++) {
            tmp[i] = other.m_data[i];
        }

        m_data = tmp;
        m_size = other.m_size;
    }

    return *this;
}



// comparison operators
bool operator== (const DynamicArray& left, DynamicArray right)
{
    if (left.m_size != right.m_size) {
        return false;
    }

    for (int i = 0; i < left.m_size; ++i) {

        if (left.m_data[i] != right.m_data[i]) {
            return false;
        }
    }

    return true;
}

bool operator!= (const DynamicArray& left, DynamicArray right)
{
    return ! (left == right);
}

// ===========================================================================
// End-of-File
// ===========================================================================
