#include <iostream>
#include "Student.cpp"
using namespace std;

int main()
{
    Student s1(10, 1001);
    cout << "Address of S1 : " << &s1;
}