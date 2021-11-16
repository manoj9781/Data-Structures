#include <iostream>
#include "Student.cpp"
using namespace std;

int main()
{
    Student s1(10, 1001);
    Student s2(13, 2001);

    // copy Constructor
    Student s3(s2);
    
    //Copy Assgnment Operator
    s2 = s1;

    Student *s4 = new Student;
    
}