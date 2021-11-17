// #include <iostream>
// #include <string.h>

// using namespace std;

// class Student
// {
// private:
//     int age;
    

// public:
// char *name;
//     Student(int age, char *name)
//     {
//         this->age = age;
//         // //Shallow Copy it uses the same address of the main block
//         // this->name = name;

//         // Deep copy of the name array so it not changes if we pass name to another object.
//         this->name = new char[strlen(name) + 1];
//         strcpy(this->name, name);
//     }

//     //Copy Consructor
//     Student(Student const &s){
//         this->age = s.age;
//         this->name = new char[strlen(s.name) + 1];
//         strcpy(this->name, name);
//     }
//     void display(){
//         cout << this->name << " " << this->age << endl;
//     }
// };

  //Initialization List 

//   class Studnet{
//       public:
//           int age;
//           int const rollNumber;

//           Studnet(int age, int rollNunber) : rollNumber(rollNumber), age(age){
//               cout << "Set constructor" << endl;
//           }
//   };


#include<iostream>
using namespace std;

class Student{
    private:
        static int totalStudent;
    public:
        int age;
        int rollNumber;
        Student(){
            totalStudent++;
        }

        static int getTotalStudent(){
            return totalStudent;
        }
};
//initiliaze the static data member

/* Static function can only access static properties
   Static function does not have the access to the this pointer */
int Student ::totalStudent = 0;