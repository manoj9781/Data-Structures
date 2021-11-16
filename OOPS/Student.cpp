#include <iostream>
using namespace std;
class Student
{
private:
    int age;

public:
    int rollNumber;

//Default Constructor
    Student(){
        cout << "Default Constructor " << endl;
    }

    Student(int a){
        cout << "Parameterized Contructor " << endl;
        age = a;
    }
    Student(int a, int r){
        cout << "Parameterized Contructor with Two arguments " << endl;
        age = a;
        rollNumber = r;
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