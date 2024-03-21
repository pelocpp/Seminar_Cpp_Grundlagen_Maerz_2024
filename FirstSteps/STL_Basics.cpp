#include <iostream>
#include <vector>
#include <algorithm>

void test_stl_01()
{
    std::vector<int> numbers;   // leer

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (int i = 0; i < numbers.size(); i++) {

        int n = numbers[i];

        std::cout << n << std::endl;
    }
}

void test_stl_02()
{
    std::vector<int> numbers;   // leer

    for (int i = 0; i < 100; i++) {

        numbers.push_back( 2 * i);

        std::cout << "Pos: "  << i 
            << ": Size: " << numbers.size() 
            << "  - Capacity: "  << numbers.capacity() << std::endl;
    }
}

void test_stl_03()
{
    std::vector<int> numbers;   // leer

    numbers.reserve(90);

    // application
    for (int i = 0; i < 100; i++) {

        numbers.push_back(2 * i);

        std::cout << "Pos: " << i
            << ": Size: " << numbers.size()
            << "  - Capacity: " << numbers.capacity() << std::endl;
    }

    numbers.shrink_to_fit();
    std::cout 
        << ": Size: " << numbers.size()
        << "  - Capacity: " << numbers.capacity() << std::endl;

    // Idealwert
}

void test_stl_04()
{
    std::vector<int> numbers;   // leer

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator anfang;
    std::vector<int>::iterator ende;

    anfang = numbers.begin();
    ende = numbers.end();

    // access element
    if (anfang == ende) {
        std::cout << "Ende erreicht." << std::endl;
        return;
    }
    int n = *anfang;
    std::cout << n << std::endl;

    anfang++;
    if (anfang == ende) {
        std::cout << "Ende erreicht." << std::endl;
        return;
    }
    n = *anfang;
    std::cout << n << std::endl;

    anfang++;
    if (anfang == ende) {
        std::cout << "Ende erreicht." << std::endl;
        return;
    }
    n = *anfang;
    std::cout << n << std::endl;

    anfang++;
    if (anfang == ende) {
        std::cout << "Ende erreicht." << std::endl;
        return;
    }
    n = *anfang;
    std::cout << n << std::endl;

}


void test_stl_05()
{
    std::vector<int> numbers;   // leer

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // transparente Traversieren eines STL-Containers
    std::vector<int>::iterator pos;
    std::vector<int>::iterator ende;

    pos = numbers.begin();
    ende = numbers.end();

    for ( ; pos != ende ; pos ++) {

        int n = *pos;
        std::cout << n << std::endl;
    }
}

void fun1(const int& n)
{
    int m;

    m = n;

    std::cout << "Value: " << n << std::endl;
}

void fun2(int n)
{
    int m;

    m = n;

    std::cout << "Value: " << n << std::endl;
}

void test_stl_06()
{
    std::vector<int> numbers;   // leer

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // traversing the container
    std::for_each(
        numbers.begin(),
        numbers.end(), 
        fun2
    );
}

void test_stl_07()
{
    std::vector<int> numbers;

    numbers.resize(100);

    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = 1;
    }

    // versus

    std::fill(                  // uses std::memset - performant
        numbers.begin(),
        numbers.end(),
        2
    );
}

int init() {

   //  std::cout << "bin hier ..." << std::endl;

    static int start = -1;

    start++;

    return 2 * start;
}


void test_stl_08()
{
    std::vector<int> numbers;

    numbers.resize(100);

    // Setzt Random Access Iterator / Container voraus
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = 2 * i;
    }

    // versus

    std::generate(
        numbers.begin(),
        numbers.end(),
        init
    );
}

void test_stl_09()
{
    std::vector<int> numbers;

    numbers.resize(100);

    std::generate(
        numbers.begin(),
        numbers.end(),
        init
    );

    int searchValue = 31;

    // Suchen: Ist die Zahl 31 im Container enthalten 
    std::vector<int>::iterator pos = std::find (
        numbers.begin(),
        numbers.end(),
        searchValue
    );

    // gefunden
    if (pos != numbers.end()) {

        std::cout << "Gefunden:     " << searchValue << std::endl;
        std::cout << "Via Iterator: " << *pos << std::endl;
    }
    else {   // pos == numbers.end()

        std::cout << "Nicht Gefunden:     " << searchValue << std::endl;
    }
}

bool searching(int element) {

    std::cout << "In searching: " << element << std::endl;

    if (element >= 3000) {
        return true;
    }
    else
        return false;
}

void test_stl_10()
{
    std::vector<int> numbers;

    numbers.resize(100);

    std::generate(
        numbers.begin(),
        numbers.end(),
        init
    );

    // Suchen: Ist im Container ein Wert größer 30 vorhanden?
    
    std::vector<int>::iterator pos = std::find_if(
        numbers.begin(),
        numbers.end(),
        searching
    );

    // gefunden
    if (pos != numbers.end()) {

        std::cout << "Gefunden: " << *pos << std::endl;
    }
    else {   // pos == numbers.end()

        std::cout << "Nicht Gefunden:     " << std::endl;
    }
}
void test_stl()
{
    test_stl_10();
}

