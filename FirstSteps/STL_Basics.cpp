#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

// C - OO nicht vorhanden
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

// Aufrufbaren Objekts

// Aufsteigende Werte
class Vorbelegen
{
private:
    int m_start; 

public:
    Vorbelegen() {
        m_start = 1;
    }

    Vorbelegen(int start) {
        m_start = start;
    }

    void setStart(int neuerStart) {
        m_start = neuerStart;
    }

    int getValue() {
        m_start++;
        return m_start;
    }

    // overloading
    int operator() () {

        m_start++;
        std::cout << "operator() ==> " << m_start << std::endl;
        return m_start;
    }

    int operator() (int x, int y) {

        std::cout << x << ", " << y << std::endl;
        m_start++;
        return m_start;
    }
};


// callable object 
void test_stl_11()
{

    Vorbelegen vorbeleger(20);

    int value;

    value = vorbeleger(1, 2);
    value = vorbeleger(3, 4);
    value = vorbeleger(5, 6);

    //value = vorbeleger.getValue();
    //value = vorbeleger.getValue();
    //value = vorbeleger.getValue();
}

void test_stl_12()
{
    std::vector<int> numbers;

    numbers.resize(5);

    Vorbelegen vorbeleger(20);

    std::generate(
        numbers.begin(),
        numbers.end(),
        vorbeleger
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        fun2
    );

    // =============

    vorbeleger.setStart(100);

    std::generate(
        numbers.begin(),
        numbers.end(),
        vorbeleger
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        fun2
    );

    // =============

    std::generate(
        numbers.begin(),
        numbers.end(),
        Vorbelegen (200)
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        fun2
    );
}

// ======================================================


std::string convert (int elem)
{
    std::string s;

    s = std::to_string(elem);

    return s;
}

void test_stl_13()
{
    std::vector<int> numbers{ 11, 12, 13, 14, 15 };

    std::for_each(
        numbers.begin(),
        numbers.end(),
        fun2
    );

    // Für eine Oberfläche

    std::vector<std::string> numbersDisplay;

    //numbersDisplay.resize(numbers.size());

    //std::transform(
    //    numbers.begin(),
    //    numbers.end(),
    //    numbersDisplay.begin(),
    //    convert
    //);

    // ODER

    std::transform(
        numbers.begin(),
        numbers.end(),
        std::back_inserter (numbersDisplay),
        convert
    );
}

void test_stl()
{
    test_stl_13();
}

