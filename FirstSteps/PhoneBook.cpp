#include "PhoneBookMap.h"
#include "PhoneBookVector.h"

#include <iostream>
#include <chrono>

void main_phonebook_map()
{
    PhoneBookMap pb;

    pb.insert("Hans", "Mueller", 123456);
    pb.insert("Tina", "Meier", 342343);
    pb.insert("Carina", "Huber", 64564645);

    pb.print();
    std::cout << "Size: " << pb.size() << std::endl;

    pb.remove("Carina", "Huber");

    pb.print();
    std::cout << "Size: " << pb.size() << std::endl;
}

void main_phonebook_vector()
{
    PhoneBookVector pb;

    pb.insert("Hans", "Mueller", 123456);
    pb.insert("Tina", "Meier", 342343);
    pb.insert("Carina", "Huber", 64564645);

    pb.print();
    std::cout << "Size: " << pb.size() << std::endl;

    pb.remove("Carina", "Huber");

    pb.print();
    std::cout << "Size: " << pb.size() << std::endl;
}


void test_benchmark_0000()
{
    std::string first;

    std::cout << sizeof (first) << std::endl;
    std::cout << sizeof(std::string().capacity()) << std::endl;
}


void test_benchmark_00()
{
    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < 100; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        std::cout << "First: " << vorname << std::endl;
        std::cout << "Last:  " << nachname << std::endl;
    }
}

const long long MaxIterations = 100000;

const long long MaxIterations2 = 100000;


void test_benchmark_01()
{
    std::cout << "Start Vector Phonebook" << std::endl;

    const auto startTime{ std::chrono::high_resolution_clock::now() };

    PhoneBookVector book;

    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < MaxIterations; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);
        
        book.insert(vorname, nachname, (size_t) 10000 + i);
    }

    std::cout << "Initialisierung fertig." << std::endl;

    const auto endTime{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;

    // Test

    const auto startTime2{ std::chrono::high_resolution_clock::now() };

    for (int k = 0; k < 5; ++ k)
    {
        for (int i = 0; i < MaxIterations2; ++i) {

            // Element löschen
        //    book.remove("First_99", "Last_99");

            // Element wieder einfügen
            book.insert("First_99", "Last_99", (size_t) 10000 + i);
        }
    }

    const auto endTime2{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

void test_benchmark_02()
{
    std::cout << "Start Vector Hashmap" << std::endl;

    const auto startTime{ std::chrono::high_resolution_clock::now() };

    PhoneBookMap book;

    std::string first{ "First_" };
    std::string last{ "Last_" };

    // Initialisierung
    for (int i = 0; i < MaxIterations; ++i) {

        std::string vorname = first + std::to_string(i);
        std::string nachname = last + std::to_string(i);

        book.insert(vorname, nachname, (size_t)10000 + i);
    }

    std::cout << "Initialisierung fertig." << std::endl;

    const auto endTime{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime - startTime).count()
        << " msecs."
        << std::endl;


    // Test

    const auto startTime2{ std::chrono::high_resolution_clock::now() };


    for (int k = 0; k < 5; ++k)
    {
        const auto startTime{ std::chrono::high_resolution_clock::now() };

        for (int i = 0; i < MaxIterations2; ++i) {

            // Element löschen
       //     book.remove("First_99", "Last_99");

            // Element wieder einfügen
            book.insert("First_99", "Last_99", (size_t) 10000 + i);
        }
    }

    const auto endTime2{ std::chrono::high_resolution_clock::now() };

    std::cout
        << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(endTime2 - startTime2).count()
        << " msecs."
        << std::endl;
}

void main_phonebook()
{
    //main_phonebook_map();
    //main_phonebook_vector();
   // test_benchmark_00();
   // test_benchmark_0000();
    test_benchmark_01();
    test_benchmark_02();
}