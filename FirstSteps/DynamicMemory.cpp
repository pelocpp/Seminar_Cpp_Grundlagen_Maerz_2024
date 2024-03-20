// ===========================================================================
// Main.cpp // Dynamic Memory Management
// ===========================================================================

#include <iostream>

namespace Dynamic_Memory_Management
{

    void dynamicMemory_Scalar()
    {
        // allocating a single int variable
        int* pInt = new int(123);
        std::cout << *pInt << std::endl;

        // releasing memory
        delete pInt;   // scalar delete
    }

    // array decay // to decay:  verkümmern, verloren gehen
    void tueWas(int* ptr)
    {
        delete[] ptr;

    }

    void tueWas(int* ptr, int length)
    {
        delete[] ptr;

    }

    void dynamicMemory_Array()
    {
        const int Length = 10;

        int feld[Length];   // 40 Bytes (1 int == 4 bytes)

        // allocating an array of int values
        int* pArray = new int[Length];

        tueWas(pArray, Length);

        // initialize array
        for (int i = 0; i < Length; ++i) {
            
            // 1. Syntax - So sieht es der Compiler ...
            *(pArray + 3) = 123;   // Wie groß ist der Offset in Bytes: 12 Byte bei einem int-Array

            // 2. Syntax - Äquivalent zur 1. Syntax - etwas angenehmer für den Anwender
            pArray[3] = 123;  // Wie groß ist der Offset in Bytes: 12 Byte bei einem int-Array

            // Frage:
            *pArray = 123;
            *(pArray + 0) = 123;
            pArray[0] = 123;


            // Ironischerweise: "C kennt keinen Datentyp Array"
            // int feld[Length];  Was ist das dann?
            // feld definiert eine Anfangsadresse.


            pArray[i] = i;  // Klar ... oder nicht klar: Syntax

            feld[i] = i;  // Diese Syntax ist auf Grund eines Arrays so definiert.
        }

        // accessing dynamically allocated array
        for (int i = 0; i < Length; ++i) {
            std::cout << pArray[i] << ' ';
        }
        std::cout << std::endl;

        // releasing memory - note: array delete (!)
        delete[] pArray;
    }

    class SimpleClass
    {
    private:
        int m_value;

    public:
        SimpleClass() { std::cout << "Default constructor SimpleClass" << std::endl; }

        SimpleClass(int, int, int) { std::cout << "User defined constructor SimpleClass" << std::endl; }

        void print() { std::cout << "SimpleClass: " << this << std::endl; }
    };


    void dynamicMemory_Object()
    {
        // allocating a single object on the stack
        SimpleClass objectOnStack;

        // allocating a single object on the heap
        SimpleClass* objectOnHeap = new SimpleClass(1, 2, 3);
        
        objectOnStack.print();

        objectOnHeap->print();

        // Für die Insider: Hmm, eigentlich gibt es den -> Operator auch nicht in C/C++
        // so wie es die eckigen Klammern nicht gibt :)
        (*objectOnHeap).print();

        // * (objectOnHeap.print() );

        // releasing memory for heap object
        delete objectOnHeap;

        // releasing memory of stack object: when function goes out of scope
    }

    void dynamicMemory_MultipleObjects()
    {
        const int Length = 10;

        // allocating a single object on the heap
        SimpleClass* objectsOnHeap = new SimpleClass[Length];

        // accessing dynamically allocated array
        for (int i = 0; i < Length; ++i) {
            objectsOnHeap[i].print();
        }
        std::cout << std::endl;

        // releasing memory for heap object
        delete[] objectsOnHeap;
    }
}

void testDynamicMemoryManagement()
{
    using namespace Dynamic_Memory_Management;

    //dynamicMemory_Scalar();
    //dynamicMemory_Array();
    // dynamicMemory_Object();
    dynamicMemory_MultipleObjects();
}

// ===========================================================================
// End-of-File
// ===========================================================================