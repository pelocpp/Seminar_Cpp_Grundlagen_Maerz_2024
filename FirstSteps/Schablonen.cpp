#include <iostream>

// Konzept: class ==========> Schablone // Template

// primäre Template
template < typename T >
class Calculator
{
public:
    static T add(T x, T y) {
        return x + y;
    }
    static T sub(T x, T y) { /* func(x, y); */ return x - y; }

    static T mul(T x, T y) { return x * y; }

    static T div(T x, T y) { return x / y; }
};

// template specialisation
//template < >
//class Calculator <int>
//{
//public:
//    static int add(int x, int y) {
//        return x + y;
//    }
//    static int sub(int x, int y) { return x - y; }
//    static int mul(int x, int y) { return x * y; }
//
//    static int div(int x, int y) { return
//    
//         (int) ( ( (double) x / y ) + 0.5  )  ;
//    }
//};

template < >
int Calculator<int>::div(int x, int y) {
    return  (int)(((double)x / y) + 0.5);
}


void testSchablonen()
{
    int result = Calculator < int >::add(3, 4);

    std::cout << result << '\n';

    double result2 = Calculator < double >::div(5.3, 7.4);

    std::cout << result2 << '\n';

    int result3 = Calculator < int >::div(3 , 8);

    std::cout << result3 << '\n';

    int result4 = Calculator < int >::div(5, 8);

    std::cout << result4 << '\n';
}