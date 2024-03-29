#pragma once

#include "IPhoneBook.h"

#include <unordered_map>
#include <map>

class PhoneBookMap : public IPhoneBook
{
private:
    std::unordered_map <std::string, size_t> m_map;

public:
    bool insert(const std::string& first, const std::string& last, size_t number) override;
    bool search(const std::string& first, const std::string& last, size_t& number) override;
    bool remove(const std::string& first, const std::string& last) override;
    void print() override;
    size_t size() override;
};