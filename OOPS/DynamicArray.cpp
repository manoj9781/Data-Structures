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

    //Copy Assignment operator
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[capacity * 2];
            for (int i = 0; i < nextIndex; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int getElement(int index) const
    {
        if (index < nextIndex)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
    }
    void add(int index, int element)
    {
        if (index < nextIndex)
        {
            data[index] = element;
        }
        else if (nextIndex == index)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};