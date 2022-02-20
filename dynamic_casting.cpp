#include <iostream>
#include <string>

class Base
{
protected:
	int m_value{};

public:
	Base(int value) : m_value{value}
	{
	}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name{};

public:
	Derived(int value, const std::string& name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

Base* getObject(bool returnDerived)
{
	if (returnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

class C
{
    std::string m_name;
public:
    const std::string& getName() const { return m_name; }
};

int main()
{
	Base* b{ getObject(true) }; // UPCASTING: Derived ptr can be converted to base ptr by normal inheritance
                                //            But, can we convert Base ptr --> Derived ptr in order to use some functionality in Derived.

	// how do we print the Derived object's name here, having only a Base pointer?
    // In this program, function getObject() always returns a Base pointer, but that pointer may be pointing to 
    // either a Base or a Derived object. In the case where the pointer is pointing to a Derived object, how would we call 
    // Derived::getName()?
    // [1] We could add a virtual function to Base called getName(). But what would this function return if you called it with 
    // a Base pointer/reference that was actually pointing to a Base object? There isn’t really any value that makes sense. 
    // Furthermore, we would be polluting our Base class with things that really should only be the concern of the Derived class.

    Derived *dPtr = dynamic_cast<Derived*>(b); // dynamic_cast is used for DOWNCASTING
    // if dPtr == NULL, it means that it was an invalid conversion
    if(dPtr)
    {
        std::cout << "Derived Object Name: " << dPtr->getName() << std::endl;
    }    
    
	delete b;

    {
        // Applying dynamic casting to references
        Base* b = new Derived(4,"Orange");
        try{
            Derived& d = dynamic_cast<Derived&>(*b); 
            std::cout << "Derived Object Name: " << d.getName() << std::endl;
        }
        catch(const std::bad_cast &e)
        {
            std::cout << e.what() << "\n";
        }
        

        // Because C++ does not have a “null reference”, dynamic_cast can’t return a null reference upon failure. 
        // Instead, if the dynamic_cast of a reference fails, an exception of type std::bad_cast is thrown. 
    }

	return 0;
}

// BEST PRACTICE:
// [1] dynamic_cast vs static_cast
// Use static_cast unless you’re downcasting (base --> derived), in which case dynamic_cast is usually a better choice. 
// However, you should also consider avoiding casting altogether and just use virtual functions.
// Why dynamic_cast is better for downcasting than static_cast?
// Downcasting can also be done with static_cast, but, there would be no runtime check to see if the conversion is valid or not
// which can lead to undefined behavior

// [2] Downcasting vs virtual functions

// There are some developers who believe dynamic_cast is evil and indicative of a bad class design. 
// Instead, these programmers say you should use virtual functions.
// In general, using a virtual function should be preferred over downcasting. 
// However, there are times when downcasting is the better choice:

// (a) When you can not modify the base class to add a virtual function (e.g. because the base class is part of the standard library)
// (b) When you need access to something that is derived-class specific (e.g. an access function that only exists in the derived class)
// (c) When adding a virtual function to your base class doesn’t make sense (e.g. there is no appropriate value for the base class to return). 
//     Using a pure virtual function may be an option here if you don’t need to instantiate the base class.

// (d) A warning about dynamic_cast and RTTI
// Run-time type information (RTTI) is a feature of C++ that exposes information about an object’s data type at runtime. 
// This capability is leveraged by dynamic_cast. Because RTTI has a pretty significant space performance cost, some compilers
//  allow you to turn RTTI off as an optimization. Needless to say, if you do this, dynamic_cast won’t function correctly.