#include <iostream>
#include <vector>
#include <random>

class Lotto
{
private:
    std::vector<int> m_numbers;

    std::default_random_engine m_random_engine;
    std::uniform_int_distribution<int> m_dist;

public:
    // c'tors
    Lotto();
    Lotto(int seed);

    // getter
    size_t drawnNumbers() const;

    // public interface
    int nextNumber();
    void addNumber(int zahl);
    void play();
    static void ausgabe(int number);
    void print();

private:
    bool numberExists(int zahl);
    void verifyNumbers();
};
