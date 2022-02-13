// Best practice (in terms of modes of inheritance):
// Use public inheritance unless you have a specific reason to do otherwise

// Protected inheritance is the least common method of inheritance. 
// It is almost never used, except in very particular cases. With protected inheritance, the public and protected members become protected, 
// and private members stay inaccessible.

// Private inheritance can be useful when the derived class has no obvious relationship to the base class, but uses the base class for 
// implementation internally. In such a case, we probably don’t want the public interface of the base class to be exposed through objects 
// of the derived class (as it would be if we inherited publicly).
// With private inheritance, the public and protected members become protected, 
// and private members stay inaccessible.



// By default, C++ invokes private inheritance (just like by default members of a class are private)
// class Derived : Base ---> PRIVATE inheritance


class Base
{
public:
    int m_public {};
protected:
    int m_protected {};
private:
    int m_private {};
};

class Pub: public Base // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pub()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        // m_private = 3; // not okay: m_private is inaccessible from derived class
    }
};

class C : public Pub
{
public:
    C()
    {
        m_public = 90;
        // if class Pub : private Base, then above line will give compiler error
        // Because (modes of inheritance + access specifier of Base members) control the way Derived class objects access Base class members
        // in main() or some function in a non-related class
        // They also control their accessibility in child classes further down in the hierarchy or in the child class of the Derived
        // class itself like here in C
    }    
}; 
int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    // base.m_protected = 2; // not okay: m_protected is protected in Base
    // base.m_private = 3; // not okay: m_private is private in Base

    Pub pub;
    pub.m_public = 1; // okay: m_public is public in Pub
    // pub.m_protected = 2; // not okay: m_protected is protected in Pub
    // pub.m_private = 3; // not okay: m_private is inaccessible in Pub

    return 0;
}