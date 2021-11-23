#include<iostream>
using namespace std;

class DynamicArray{
    private:
    int *data;
    int capacity;
    int nextIndex;

    public:
    void print(){
        for (int i = 0; i < nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};