#include<iostream>
//                         ----------------  
//    -------------------> | PoweredDevice | <-------------- 
//    |                    ----------------                |
//    |                                                    |
//    |                                                    |   
// --------                                           -----------
// Printer |                                          | Scanner | 
// --------                                           -----------
//     ^                                                   ^ 
//     |                                                   |
//     |                      ----------                   |
//     |--------------------- | Copier | ------------------|
//                            ----------

// Only 1 copy of PoweredDevice

// Virtual base classes:
// To share a base class, simply insert the “virtual” keyword in the inheritance list of the derived class. 
// This creates what is called a virtual base class, which means there is only one base object. 
// The base object is shared between all objects in the inheritance tree and it is only constructed once. 

class PoweredDevice
{
private:
    int m_power;
public:    
    PoweredDevice(int power) : m_power(power) { std::cout << "PoweredDevice constructor: " << power << "\n";  }
};

// Second, note that the Scanner and Printer constructors still have calls to the PoweredDevice constructor. 
// When creating an instance of Copier, these constructor calls are simply ignored because Copier is responsible 
// for creating the PoweredDevice, not Scanner or Printer. However, if we were to create an instance of Scanner or Printer, 
// those constructor calls would be used, and normal inheritance rules apply.
class Printer : virtual public PoweredDevice
{
private:
    int m_printer;
public:
    Printer(int printer, int power) : PoweredDevice(power),m_printer(printer) 
    {   std::cout << "Printer constructor:" << printer << "\n";  }
};

class Scanner : virtual public PoweredDevice
{
private:
    int m_scanner;
public:
    Scanner(int scanner, int power) : PoweredDevice(power),m_scanner(scanner) 
    {   std::cout << "Scanner constructor:" << scanner << "\n";  }
};

// Order in which classes are called here, decides the order of constructor call for the classes.
// Here, 1st Printer's constructor is called & then Scanner's constructor
class Copier: public Printer, public Scanner
{
public:
    // The PoweredDevice constructor had to be called here or else, there would be compile error
    // REASON: In a diamond structure, compiler identifies it & demands that the class which was made virtual by it's children
    // should be constructed by the class constructor, whose object is being created

    // Virtual base classes (PoweredDevice) are always created before non-virtual base classes (Printer & Scanner), 
    // which ensures all bases get created before their derived classes.
    // If a class inherits one or more classes that have virtual parents, the most derived class is responsible for 
    // constructing the virtual base class.
    Copier(int printer, int scanner, int power) : PoweredDevice(power), Printer(printer,power), Scanner(scanner,power)    {   }
};

// if Scanner and Printer share a PoweredDevice base class, who is responsible for creating it? 
// The answer, as it turns out, is Copier. The Copier constructor is responsible for creating PoweredDevice. 
// Consequently, this is one time when Copier is allowed to call a non-immediate-parent constructor directly

// All classes inheriting a virtual base class will have a virtual table, even if they would normally not 
// have one otherwise, and thus instances of the class will be larger by a pointer.
int main()
{
    Copier cp{2,3,4};
}