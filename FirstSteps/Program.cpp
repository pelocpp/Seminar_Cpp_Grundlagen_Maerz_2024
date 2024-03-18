#include <iostream>  // STL Standard Template Library


#include "Time.h"


//int main()
//{
//    // console output
//    std::cout << "Hello World" << std::endl;
//
//    //char ch;
//    //std::cin >> ch;
//
//    return 123;
//}

int main()
{
    Time now (11, 54, 9999);       // erstes Objekt

    // C#:  Time now = new Time();
    // C#:  Time now;  now ist in C# eine Referenz (Pointer)
    // C++: Time now;  ACHTUNG: Ja, hier haben wir ein OBJEKT (Stack)


   // now.m_hours = 9999;   // Wertzuweisung - Überprüfung: 0 .. 23

    //now.m_hours = 10;
    //now.m_minutes = 20;
    //now.m_seconds = 25;

    now.setHours(10);
    now.setMinutes(20);
    now.setSeconds(25);

    // C#
    // now.Hours = 10;

    now.print();

    // a) Lesender Zugriff: getter
    // int stunden = now.m_hours;
    int stunden = now.getHours();

    // b) Schreibender Zugriff: setter
    // now.m_hours = 0;
    now.setHours(0);

    now.reset();
    now.print();

    Time pause;     // zweites Objekt

    //pause.m_hours = 10;
    //pause.m_minutes = 30;
    //pause.m_seconds = 0;
    pause.setHours(10);
    pause.setMinutes(30);
    pause.setSeconds(0);

    pause.print();
}
