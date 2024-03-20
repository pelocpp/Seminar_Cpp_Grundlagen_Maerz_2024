// ===========================================================================
// DynamicArray_Main.cpp
// ===========================================================================

#include "DynamicArray.h"

static void testDynamicArray01()
{
    DynamicArray array(3);
    array.print();
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.print();
}

static void testDynamicArray02()
{
    DynamicArray array(3);
    array.print();

    array.fill(123);
    array.print();

    array.release();
    array.print();
}


static void testDynamicArray03()
{
    DynamicArray array1(3);
    array1.fill(10);
    array1.print();

    DynamicArray array2(3);
    array2.fill(20);
    array2.print();

    // Wertzuweisung
    DynamicArray array0;
    array0 = (array1 = array2);

    array1 = array1;   // Selbstzuweisung:  "Suizid"

    //// Objekt kopieren - Kopier-Konstruktor
    DynamicArray array3 (array2);
    array3.fill(20);
    array3.print();
}

void exerciseDynamicArray()
{
    //testDynamicArray01();
    //testDynamicArray02();
    testDynamicArray03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
