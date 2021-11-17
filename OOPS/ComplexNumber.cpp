#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void print()
    {
        cout << this->real << "+" << this->imaginary << "i" << endl;
    }
    void add(ComplexNumber c)
    {
        this->real = this->real + c.real;
        this->imaginary = this->imaginary + c.real;
    }
    void multiply(ComplexNumber c)
    {
        this->real = (this->real * c.real) - (this->imaginary * c.imaginary);

        this->imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);
    }
};