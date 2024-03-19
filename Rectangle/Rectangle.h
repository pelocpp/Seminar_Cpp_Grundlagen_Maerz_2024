// ===============================================================================
// Rectangle.h
// ===============================================================================

#pragma once

#include <iostream>

#include "Point.h"

class Rectangle
{
    friend bool operator == (const Rectangle&, const Rectangle&);

private:
    double m_x;
    double m_y;
    double m_width;
    double m_height;

public:
    // c'tors
    Rectangle();

    Rectangle(double x, double left, double width, double height);

    // getter/setter
    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;

    void setX(double x);
    void setY(double y);
    void setWidth(double width);
    void setHeight(double height);

    // public interface // methods
    double circumference() const;
    double diagonal() const;
    double area() const;
    bool isSquare() const;

    // Signatur einer Methode / Funktion
    // Name der Methode, Rückgabetyp, Datentypen der Parameter
    // NICHT: Etwaige Namen der Parameter
    void moveTo(double x, double y);

    bool equals(const Rectangle&) const;

    Point center();
    Rectangle intersection(Rectangle);
    void print();

    // operators
    // bool operator == (const Rectangle& other) const;
};

// =======================================================





// ===============================================================================
// End-of-File
// ===============================================================================
