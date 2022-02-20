#include<iostream>

class Person
{
private:
    std::string m_name;
    int m_age;
    int m_id;
    static int personCount;
public:
    Person(std::string name,int age) : m_name(name),m_age(age), , m_id(++personCount){  }
    std::string getName() const {  return m_name; }
    int getAge() const {  return m_age;  }
    int getID() const {  return m_id;  }
};

class Employee
{
private:
    std::string m_employer;
    int m_wage;
    int m_id;
    static int employeeCount;
public:
    Employee(std::string employer,int wage) : m_employer(employer), m_wage(wage), m_id(++employeeCount) {  }
    std::string getEmployer() const {  return m_employer; }
    int getWage() const {  return m_wage;  }
    int getID() const {  return m_id;  }
};

class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade;
public:
    Teacher(std::string name,int age,std::string employer,int wage,int teachesGrade) : 
        Person(name,age),Employee(employer,wage),m_teachesGrade(teachesGrade)
    {
        
    }
};

int Person::personCount = 0;
int Employee::employeeCount = 0;
int main()
{
    Teacher rohan("Rohan",32,"Samuel",50000,10);

    // What to do when same function name getID() is to be called?
    // std::cout << "Rohan's personID = " << rohan.getID() << std::endl; --> COMPILE ERROR
    std::cout << "Rohan's personID = " << rohan.Person::getID() << std::endl;
    std::cout << "Rohan's employeeID = " << rohan.Employee::getID() << std::endl;
}