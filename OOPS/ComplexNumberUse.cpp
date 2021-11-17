#include<iostream>
using namespace std;
#include "ComplexNumber.cpp"
int main(){
    int real, imaginary;
    int real1, imaginary1;
    cin >> real >> imaginary;
    cin >> real1 >> imaginary1;

    ComplexNumber c1(real, imaginary);
    ComplexNumber c2(real1, imaginary1);

   
    c1.multiply(c2);
    c1.print();
    c2.print();
}