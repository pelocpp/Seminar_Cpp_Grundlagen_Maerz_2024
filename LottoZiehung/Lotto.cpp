#include "Lotto.h"

// c'tors
Lotto::Lotto() : m_random_engine(123), m_dist(1, 49) {}

Lotto::Lotto(int seed) : m_random_engine(seed), m_dist(1, 49) {}

// getter
size_t Lotto::drawnNumbers() const { return m_numbers.size(); }

// public interface
int Lotto::nextNumber()
{
    int number = m_dist(m_random_engine);
    std::cout << "  ... got " << number << std::endl;
    return number;
}

bool Lotto::numberExists(int zahl)
{
    std::vector<int>::iterator pos = std::find(
        m_numbers.begin(),
        m_numbers.end(),
        zahl
    );

    return pos != m_numbers.end();
};

void Lotto::addNumber(int zahl)
{
    std::cout << "    ... enter " << zahl << std::endl;
    m_numbers.push_back(zahl);
}

void Lotto::play()
{
    for (int i = 0; i < 6; ++i) {

        int zahl;
        do {
            zahl = nextNumber();
        } while (numberExists(zahl));

        addNumber(zahl);
        verifyNumbers();
    }
}

void Lotto::ausgabe(int number) {
    std::cout << number << ", ";
}

void Lotto::print()
{
    std::cout << "\n";
    std::cout << "Ziehung der Lottozahlen:\n";
    std::cout << "========================\n";

    std::for_each(
        m_numbers.begin(),
        std::prev(m_numbers.end()),
        ausgabe
    );

    int last = m_numbers.back();
    std::cout << last;
}


void Lotto::verifyNumbers()
{
    for (int i = 0; i < m_numbers.size(); ++i) {

        int wert = m_numbers[i];

        for (int k = 0; k < m_numbers.size(); ++k) {

            if (k == i)
                continue;

            if (wert == m_numbers[k]) {

                throw std::exception("Illegal numbers found");
            }
        }
    }
}

void main_lotto()
{
    Lotto lotto(55);
    lotto.play();
    lotto.print();
}

