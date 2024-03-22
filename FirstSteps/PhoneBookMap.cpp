// Realisierung PhoneBook mit std::unordered_map

#include "PhoneBookMap.h"

#include <iostream>
#include <utility>
#include <algorithm>

// -------------------------------------------------------------------------------

bool PhoneBookMap::search(const std::string& first, const std::string& last, size_t& number)
{
    std::string key = first + "_" + last;  // build key

    std::unordered_map <std::string, size_t>::iterator pos = m_map.find(key);

    // auto pos2 = m_map.find(key);

    if (pos == m_map.end()) {

        std::cout << first << " " << last << " not found!" << std::endl;

        return false;
    }
    else {

        std::pair<std::string, size_t> result = *pos;

        number = result.second;   // rausschreiben
    
        std::cout << first << " " << last << " has number " << number << std::endl;

        return true;
    }
}

// -------------------------------------------------------------------------------

bool PhoneBookMap::remove(const std::string& first, const std::string& last)
{
    std::string key = first + "_" + last;

    size_t numErased = m_map.erase(key);

    return (numErased == 1) ? true : false;
}

// -------------------------------------------------------------------------------

bool PhoneBookMap::insert(const std::string& first, const std::string& last, size_t number)
{
    // "Hans", "Mueller" ==> Key: "Hans"_"Mueller"

    std::string key = first + "_" + last;
     
    // insert ...

    std::pair<std::string, size_t> entry(key, number);

    m_map.insert(entry);   // returns a bool value set to true if and only if the insertion took place.

    return true; // siehe Zeile zuvor
}

// -------------------------------------------------------------------------------

static void printEntry(const std::pair<std::string, size_t>& entry) {

    std::string key = entry.first;
    size_t value = entry.second;

    // key zerlegen
    size_t pos = key.find("_");

    std::string first = key.substr(0, pos);
    std::string last = key.substr(pos + 1);

    // sehr kurz
    // std::cout << key << ": " << value << std::endl;

    std::cout << first << " " << last << ": " << value << std::endl;
}

void PhoneBookMap::print()
{
    std::for_each(
        m_map.begin(),
        m_map.end(),
        printEntry
    );
}

// -------------------------------------------------------------------------------

size_t PhoneBookMap::size()
{
    return m_map.size();
}

// -------------------------------------------------------------------------------
