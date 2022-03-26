#include<iostream>
#include"PriorityQueue.h"
using namespace std;

int main(){
    PriorityQueue p;
    p.insert(6);
    p.insert(2);
    p.insert(4);
    p.insert(79);
    p.insert(0);
    p.insert(64);
    p.insert(45);
    p.insert(23);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while(!p.isEmpty()){
        cout << p.removeMin() << " ";
    }
    cout << endl;
}
