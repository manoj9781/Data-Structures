#include <iostream>
using namespace std;
class Student
{
private:
    int age;

public:
    int rollNumber;

    //Constructor are special function which have some properties
    /*1. constructor have same name as class 
    2. Contructor have no return type
    3. For every object one constructor called once in object life
    4.  Defalut Constructor have no input arguments
    */

    //Default Constructor
    Student()
    {
        cout << "Default Constructor " << endl;
    }

    Student(int a)
    {
        cout << "Parameterized Contructor " << endl;
        age = a;
    }

    /* This is the special keyword which holds the address of the current
    object.
    This is the pointer also 
   */

    Student(int a, int r)
    {
        cout << "Parameterized Contructor with Two arguments " << endl;
        cout << "This : " << this << endl;
        age = a;
        rollNumber = r;
    }

    //Destructor 
    /*
    Deallocate the memory of the objects 
    same name as the class name 
    No return type 
    No input arguments
    starts with ~ sign
    */

   ~Student(){
       cout << "Destructor Called " << endl;
   }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }
    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
    void setRollNumber(int roll)
    {
        rollNumber = roll;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
};