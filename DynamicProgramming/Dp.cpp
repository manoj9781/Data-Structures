#include<iostream>
using namespace std;

// Complexity of this function is 2 power of n
// Recursive solution Brute Force approach
int fibo(int n){
    if(n <=1){
        return 1;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}