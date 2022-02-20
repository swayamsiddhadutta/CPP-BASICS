// a) Write an Apple class and a Banana class that are derived from a common Fruit class. Fruit should have two members: a name, and a color.
// OUTPUT: 
// My apple is red.
// My banana is yellow.

// b) Add a new class to the previous program called GrannySmith that inherits from Apple.
// My apple is red.
// My banana is yellow.
// My granny smith apple is green.

#include<iostream>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;
public:
    Fruit(const std::string& name,const std::string& color) : m_name(name),m_color(color)
    {
        //std::cout << "Fruit is created\n";
    }

    const std::string& getName() const
    {
        return m_name;
    }

    const std::string& getColor() const
    {
        return m_color;
    }

    ~Fruit()
    {
        //std::cout << "Fruit is destroyed\n";
    }
};

class Apple : public Fruit
{
protected:
    // This cannot be called outside, can be called in sub-class
    Apple(const std::string name,const std::string& color) : Fruit(name,color) 
    {
        //std::cout << "Apple is created\n";
    }
public:
    Apple(const std::string& color="red") : Fruit("apple",color)
    {
        //std::cout << "Apple is created\n";
    }
    ~Apple()
    {
        //std::cout << "Apple is destroyed\n";
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple("GrannySmith apple","green")
    {
        //std::cout << "GrannySmith is created\n";
    }

    ~GrannySmith()
    {
        //std::cout << "GrannySmith is destroyed\n";
    }
};

class Banana : public Fruit
{
public:
    Banana(const std::string color="yellow") : Fruit("banana",color)
    {
        //std::cout << "Banana is created\n";
    }

    ~Banana()
    {
        //std::cout << "Banana is destroyed\n";
    }
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}