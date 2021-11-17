#include<iostream>

using namespace std;

class Student{
    private:
        int age;
        char *name;
        public:
        Student(int age, char *name){
            this->age = age;
            //Shallow Copy it uses the same address of the main block
            this->name = name;
        }
};