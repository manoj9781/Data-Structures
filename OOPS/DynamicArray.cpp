#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int capacity;
    int nextIndex;

public:
    DynamicArray()
    {
        this->data = new int[5];
        this->capacity = 5;
        this->nextIndex = 0;
    }
    
    //Copy Constructor
    DynamicArray(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }

    void operator=(DynamicArray const &d){
        this->data = new int[d.capacity];
        for (int i = 0; i < nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};