#include<iostream>
using namespace std;

int power(int x, int n){
    if(n!= 0){
        return (x * power(x, n - 1));
    }
    else
        return 1;
}

double geometricSum(int k){
    if(k == 0){
        return 1;
    }
    int ans = power(2, k);
    return ((double)1 / ans) + geometricSum(k - 1);
}

int main(){
    int k;
    cin >> k;
    cout << geometricSum(k);
}