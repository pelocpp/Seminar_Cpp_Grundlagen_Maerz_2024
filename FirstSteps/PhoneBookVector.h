#pragma once

#include "IPhoneBook.h"

#include <vector>

class PhoneBookVector : public IPhoneBook
{
private:

    // nested class - vor dem Anwender versteckt
    class Entry
    {
    public:
        Entry (const std::string& first, const std::string& last, size_t number) 
            : m_first(first), m_last(last), m_number(number)  // memberwise initialization list
        {}

        std::string m_first;
        std::string m_last;
        size_t m_number;
    };


    std::vector <Entry> m_vec;


public:
    bool insert(const std::string& first, const std::string& last, size_t number) override;
    void print() override;
    size_t size() override;
};