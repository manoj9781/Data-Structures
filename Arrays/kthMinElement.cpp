#include<iostream>
#include<queue>
using namespace std;

int kthMinElement(int input[], int n, int k){
    if(n == 0){
        return -1;
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        pq.push(input[i]);
    }
    while(pq.size() > k){
        pq.pop();
    }
    return pq.top();
}

    int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int *input = new int[n];
    cout << "Enter Elements" << endl;
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    int k;
    cout << "Enter value of K" << endl;
    cin >> k;
    cout << kthMinElement(input, n, k) << endl;
}