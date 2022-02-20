#include<iostream>
// --------------                                  ----------------
// PoweredDevice |                                 | PoweredDevice |
// --------------                                  ----------------
//    ^                                                    ^
//    |                                                    |   
// --------                                           -----------
// Printer |                                          | Scanner | 
// --------                                           -----------
//     ^                                                   ^ 
//     |                                                   |
//     |                      ----------                   |
//     |--------------------- | Copier | ------------------|
//                            ----------

// 2 copies of PoweredDevice

class PoweredDevice
{
private:
    int m_power;
public:    
    PoweredDevice(int power) : m_power(power) { std::cout << "PoweredDevice constructor: " << power << "\n";  }
};

class Printer : public PoweredDevice
{
private:
    int m_printer;
public:
    Printer(int printer, int power) : PoweredDevice(power),m_printer(printer) 
    {   std::cout << "Printer constructor:" << printer << "\n";  }
};

class Scanner : public PoweredDevice
{
private:
    int m_scanner;
public:
    Scanner(int scanner, int power) : PoweredDevice(power),m_scanner(scanner) 
    {   std::cout << "Scanner constructor:" << scanner << "\n";  }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int printer, int scanner, int power) : Printer(printer,power), Scanner(scanner,power)    {   }
};

int main()
{
    Copier cp{2,3,4};
}