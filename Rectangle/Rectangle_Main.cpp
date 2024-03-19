#include "Rectangle.h"

// Als globale Funktion:
bool operator == (const Rectangle& left, const Rectangle& right) {

    if (left.m_x != right.m_x) {
        return false;
    }
    else if (left.m_y != right.m_y) {
        return false;
    }
    else if (left.m_width != right.m_width) {
        return false;
    }
    else if (left.m_height != right.m_height) {
        return false;
    }
    else
    {
        return true;
    }

    //if (left.getX() != right.getX()) {
    //    return false;
    //}
    //else if (left.getY() != right.getY()) {
    //    return false;
    //}
    //else if (left.getWidth() != right.getWidth()) {
    //    return false;
    //}
    //else if (left.getHeight() != right.getHeight()) {
    //    return false;
    //}
    //else
    //{
    //    return true;
    //}
}




static void test01_ctors()
{
    Rectangle rect1;
    rect1.print();
    Rectangle rect2(3, 3, 5, 5);
    rect2.print();
    Rectangle rect3(3, 3, 5, 1);
    rect3.print();
    Rectangle rect4(3, 3, 1, 1);
    rect4.print();
    Rectangle rect5(3, 3, 1, 5);
    rect5.print();
}

static void test02_methods()
{
    Rectangle rect(3, 4, 9, 10);
    rect.print();
    std::cout << "Circumference: " << rect.circumference() << std::endl;
    std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
    std::cout << "Area:          " << rect.area() << std::endl;
    std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
}

static void test03_center()
{

    Rectangle rect1(1, 3, 3, 1);
    rect1.print();
    Point p = rect1.center();
    std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;

    Rectangle rect2(1, 4, 4, 1);
    rect2.print();
    p = rect2.center();
    std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;
}

static void test04_move()
{

    Rectangle rect(1, 1, 4, 5);
    rect.print();
    rect.moveTo(5, -5);
    rect.print();
}

static void test05_intersection()
{

    Rectangle rect1(4, 8, 9, 5);
    Rectangle rect2(2, 10, 8, 6);
    Rectangle rect = rect1.intersection(rect2);

    rect1.print();
    rect2.print();
    rect.print();

    Rectangle rect3(7, 9, 9, 4);
    rect = rect1.intersection(rect3);
    rect.print();

    rect = rect3.intersection(rect3);
    rect.print();

    Rectangle rect4(6, 7, 10, 5);
    rect = rect1.intersection(rect4);
    rect.print();
}

static void test06_equals()
{
    Rectangle rect1(1, 1, 4, 5);

    Rectangle rect2(1, 1, 4, 5);


    bool equals;
    
    equals = rect1.equals(rect2);  // Objekt-Orientiert

    equals = (rect1 == rect2);     // Operatorenschreibweise // Infix-Schreibweise

    // Nur auf Grund des Verständnisses:
    // equals = rect1.operator== (rect2);

    // Nur auf Grund des Verständnisses:
    // equals = operator== (rect1, rect2);

    if (rect1 == rect2) {
        std::cout << "Sind gleich" << std::endl;
    }

    std::cout << equals << std::endl;
    rect2.setX(10);
    equals = rect1.equals(rect2);
    std::cout << equals << std::endl;
}




static void test_rectangle_output()
{
    Rectangle rect(3, 3, 5, 5);


    // Operator<<:
    // 1. Operand:    std::cout vom Typ class std::ostream
    // 2. Operand:                      class Rectangle

    std::cout << rect << '.' << std::endl;    // fluent programming style


    //std::cout << rect.getX() << std::endl;
    //std::cout << rect.getY() << std::endl;
    //std::cout << rect.getWidth() << std::endl;
    //std::cout << rect.getHeight() << std::endl;
}


void exerciseRectangle()
{
    //test01_ctors();
    //test02_methods();
    //test03_center();
    //test04_move();
    //test05_intersection();
    //test06_equals();
    test_rectangle_output();
}

// ===========================================================================
// End-of-File
// ===========================================================================
