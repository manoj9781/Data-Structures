#include <iostream>
#include <string.h>

using namespace std;

class Student
{
private:
    int age;
    

public:
char *name;
    Student(int age, char *name)
    {
        this->age = age;
        // //Shallow Copy it uses the same address of the main block
        // this->name = name;

        // Deep copy of the name array so it not changes if we pass name to another object.
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    //Copy Consructor
    Student(Student const &s){
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, name);
    }
    void display(){
        cout << this->name << " " << this->age << endl;
    }
};