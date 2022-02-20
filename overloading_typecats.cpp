#include <iostream>

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
        : m_dollars{ dollars }
    {
    }

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents { m_dollars * 100 }; }

    // Allow us to convert Dollars into int
    operator int() const {  return m_dollars; }
};

void printCents(Cents cents)
{
    std::cout << cents << std::endl; // cents will be implicitly cast to an int here
}

void printInt(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here
    printInt(dollars); // dollars --> int

    Cents cent{4};
    printInt(cent); // cents --> int
    std::cout << '\n';

    int numCents = cent;
    return 0;
}