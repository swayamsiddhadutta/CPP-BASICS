// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
//Q) Let’s implement our Fruit example that we talked about in our introduction to inheritance. 
//   Create a Fruit base class that contains two private members: a name (std::string), and a color (std::string). 
//   Create an Apple class that inherits Fruit. 
//   Apple should have an additional private member: fiber (double). Create a Banana class that also inherits Fruit. Banana has no additional members.
//   EXPECTED OUTPUT:
// Apple(Red delicious, red, 4.2)
// Banana(Cavendish, yellow)
#include<iostream>
using namespace std;

class Fruit
{
private:
    string m_name;
    string m_color;
public:
    Fruit(const string& name, const string& color) : m_name(name), m_color(color)
    {

    }

    string getName() const
    {
        return m_name;
    }

    string getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{
private:
    double m_fiber;
public:
    Apple(const string& name,const string& color,double fiber) : Fruit(name,color), m_fiber(fiber)
    {

    }

    double getFiber() const
    {
        return m_fiber;
    }
};

// OPERATOR overload of <<
ostream& operator<<(ostream& os,const Apple& a)
{
    os << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ")";
    return os;
}

class Banana : public Fruit
{
public:
    Banana(const string& name, const string& color) : Fruit(name,color)
    {
        
    }
};

ostream& operator<<(ostream& os,const Banana& b)
{
    os << "Banana(" << b.getName() << ", " << b.getColor() << ")";
    return os;
}
int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}