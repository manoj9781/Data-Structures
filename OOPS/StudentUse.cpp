#include <iostream>
#include "Student.cpp"
using namespace std;

int main()
{
    Student s1;
    int age;
    cout << "Enter Age" << endl;
    cin >> age;
    s1.setAge(age);
    int rollNumber;
    cout << "Enter Roll Number" << endl;
    cin >> rollNumber;
    s1.setRollNumber(rollNumber);
    Student *s2 = new Student;
    cout << "Enter Age" << endl;
    cin >> age;
    s2->setAge(age);
    cout << "Enter Roll Number" << endl;
    cin >> rollNumber;
    s2->setRollNumber(rollNumber);
    s1.display();
    s2->display();
}