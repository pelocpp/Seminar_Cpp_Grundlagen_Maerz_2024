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

    class Contains
    {
    public:
        Contains(const std::string& first, const std::string& last)
            : first(first), last(last)
        {}

        const std::string& first;
        const std::string& last;

        // Ironisch: Lamda Funkion
        bool operator() (const Entry& entry) const {

            return entry.m_first == first && entry.m_last == last;
        }
    };

    //class Contains
    //{
    //public:
    //    Contains(const std::string& first, const std::string& last)
    //        : m_first(first), m_last(last)
    //    {}

    //    const std::string& m_first;
    //    const std::string& m_last;

    //    bool operator()(const Entry& entry) const {

    //        return entry.m_first == m_first && entry.m_last == m_last;
    //    }
    //};

    std::vector<Entry> m_vec;


public:
    // public interface
    bool insert(const std::string& first, const std::string& last, size_t number) override;
    bool search(const std::string& first, const std::string& last, size_t& number) override;
    bool remove(const std::string& first, const std::string& last) override;
    void print() override;
    size_t size() override;

private:
    // private helper methods
    bool contains(const std::string& first, const std::string& last);

    static void printEntry(const Entry& entry);
};