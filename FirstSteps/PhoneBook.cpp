#include "PhoneBookMap.h"

#include <iostream>

void main_phonebook()
{
    PhoneBookMap pb;

    pb.insert("Hans", "Mueller", 123456);
    pb.insert("Tina", "Meier", 342343);
    pb.insert("Carina", "Huber", 64564645);

    pb.insert("Hans", "Mueller", 123456);

    pb.print();

    std::cout << "Size: " << pb.size() << std::endl;
}