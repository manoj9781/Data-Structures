#include <iostream>
#include "Student.cpp"
using namespace std;

int main()
{
    Student s1;
    Student s2(10);
    Student s3(15, 1001);
    s1.display();
    s2.display();
    s3.display();
}