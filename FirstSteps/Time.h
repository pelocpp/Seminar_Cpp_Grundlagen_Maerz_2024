#pragma once


// Header-File:
// Die Schnittstelle eine Klasse

class Time
{
private:
    // member data / instance variables
    int m_seconds;
    int m_minutes;
    int m_hours;
 //   int sekunden;

public:
  //  void setSekunden(int sekunden);

    // Constructor
    Time();                                     // Ohne Parameter: Standard-Konstruktor
    Time(int hours, int seconds, int minutes);  // user-defined c'tor


    // setter / getter
    void setHours(int hour);
    void setSeconds(int seconds);
    void setMinutes(int minutes);

    // Alternativ bei "kurzen" Methoden: Realisierung im Header
    int getHours();
    int getSeconds() { return m_seconds; }
    int getMinutes() { return m_minutes; }

    // public interface / methods
    void reset();       // 00:00:00
    void increment();   // 9:51:30  => 9:51:31 // 9:51:59 => 9:52:00
    void print();       // Ausgabe in der Konsole
};

