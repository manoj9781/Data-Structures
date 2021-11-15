#include <iostream>
using namespace std;
class Student
{
private:
    int age;

public:
    int rollNumber;

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