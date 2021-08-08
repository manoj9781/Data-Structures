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

/*
Memoization technique of fibonacci Number to improve the time 
complexity. The complexity of this function is order of n.
Memoization technique uses bottom-down approach
*/

int fibonacciNumber(int *ans, int n){
    if(n <= 1){
        ans[n] = n;
        return 1;
    }
    if(ans[n-1] == 0){
        ans[n - 1] = fibonacciNumber(ans, n - 1);
    }
    if(ans[n-2] == 0){
        ans[n - 2] = fibonacciNumber(ans, n - 2);
    }

    ans[n] = ans[n - 1] + ans[n - 2];
    return ans[n];
}

int fibonacciNumber(int n){
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++){
        ans[i] = 0;
    }
    return fibonacciNumber(ans, n);
}

int main(){
    int n;
    cin >> n;
    cout << fibonacciNumber(n) << endl;
    cout << fibo(n) << endl;
}