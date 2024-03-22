// Realisierung PhoneBook mit std::vector

#include "PhoneBookVector.h"

#include <iostream>
#include <utility>
#include <algorithm>

// -------------------------------------------------------------------------------

PhoneBookVector::PhoneBookVector()
{
  //  m_vec.reserve(10000);
}
// -------------------------------------------------------------------------------

bool PhoneBookVector::insert(const std::string& first, const std::string& last, size_t number)
{
    if (contains(first, last)) {
        return false;
    }

    Entry entry(first, last, number);
    m_vec.push_back(entry);

    return true;
}

// -------------------------------------------------------------------------------

// Parameter 1 und 2:  first / last  : Input
// Parameter 3:        number        : Output
bool PhoneBookVector::search(const std::string& first, const std::string& last, size_t& number) {

    Contains cont(first, last);

    std::vector<Entry>::iterator pos = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        cont
    );

    if (pos == m_vec.end()) {

        std::cout << first << " " << last << " not found!" << std::endl;

        return false;
    }
    else {

        const Entry& result = *pos;

        number = result.m_number;   // "rausschreiben"

        std::cout << first << " " << last << " has number " << number << std::endl;

        return true;
    }
}

// -------------------------------------------------------------------------------

bool PhoneBookVector::remove(const std::string& first, const std::string& last)
{
    Contains cont(first, last);

    std::vector<Entry>::iterator pos = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        cont
    );

    if (pos == m_vec.end()) {

        std::cout << first << " " << last << " not found!" << std::endl;

        return false;
    }
    else {

        m_vec.erase(pos);

        return true;
    }
}

// -------------------------------------------------------------------------------



void PhoneBookVector::printEntry(const Entry& entry)
{
    std::cout << entry.m_first << " " << entry.m_last << ": " << entry.m_number << std::endl;
}

void PhoneBookVector::print()
{
    std::for_each(
        m_vec.begin(),
        m_vec.end(),
        printEntry
    );
}

// -------------------------------------------------------------------------------

size_t PhoneBookVector::size()
{
    return m_vec.size();
}

// -------------------------------------------------------------------------------

bool PhoneBookVector::contains(const std::string& first, const std::string& last)
{
    Contains cont(first, last);

    std::vector<Entry>::iterator pos = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        cont
    );

    return pos != m_vec.end();
}

// -------------------------------------------------------------------------------
