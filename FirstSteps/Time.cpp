
// Implementierungsdatei zur Klasse Time

#include "Time.h"

#include <iostream>  // STL Standard Template Library


//
//void Time::setSekunden(int sekunden)
//{
//    // member       = parameter
//    this->sekunden  = sekunden;
//}


// Default C'tor (Constructor)
// 1. Variante: Klassisch
//Time::Time()
//{
//    m_hours = 0;
//    m_minutes = 0;
//    m_seconds = 0;
//}

// 2. Variante: Mit Member Initializer List
//Time::Time() : m_hours (0), m_minutes(0), m_seconds (0)
//{}

// 3. Variante: Mit Member Initializer List UND Verketten von Konstruktoren
// Constructor Chaining
Time::Time() : Time(0, 0, 0)
{
}


Time::Time(int hours, int minutes, int seconds)
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;

    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);

    // Ausnahmen // Exception :  HIER NEIN !!!!!!!!!!!
    // File  Open
    // File f;
    // f.setPath("C:/XX"); f.setName("C:/XX");
}



// getter
int Time::getHours()
{
    return m_hours;
}


// setter
// Schreibender Zugriff: Wertebereich überprüfen !!!
void Time::setHours(int hour)
{
    if (hour >= 0 && hour < 24) {
        m_hours = hour;
    }
    else {
        std::cout << "Falscher Wert fuer Stunden: " << hour << std::endl;
    }
}

void Time::setMinutes(int minutes)
{
    if (0 <= minutes && minutes < 60) {
        m_minutes = minutes;
    }
    else {
        // we don't modify the current value of 'm_minutes'
        std::cout << "Wrong value for minutes: " << minutes << std::endl;
    }
}

void Time::setSeconds(int seconds)
{
    if (0 <= seconds && seconds < 60) {
        m_seconds = seconds;
    }
    else {
        // we don't modify the current value of 'm_seconds'
        std::cout << "Wrong value for seconds: " << seconds << std::endl;
    }
}



void Time::reset()
{
    m_seconds = 0;
    m_minutes = 0;
    m_hours = 0;
}

void Time::print()
{
    std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
}

void Time::increment()
{
    m_seconds++;
    // m_seconds = m_seconds + 1;

    if (m_seconds >= 60)
    {
        m_seconds = 0;
        m_minutes++;

        if (m_minutes >= 60)
        {
            m_minutes = 0;
            m_hours++;

            if (m_hours >= 24)
            {
                m_hours = 0;
            }
        }
    }
}
