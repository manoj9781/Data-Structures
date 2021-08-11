#include<iostream>
#include<climits>
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

/*
Solution using Dynamic Programming and the complexity 
of this function is also order of n
*/

int fiboBetter(int n){
    int *ans = new int[n + 1];
    ans[0] = 1; //Trivial Solution
    ans[1] = 1; //Trivial solution

    for (int i = 2; i <= n; i++){
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

/*
Min Steps to reduce a number to 1 using given set of operations
The complexity of this function is order 3 power n using Bruteforce solution
*/

int minSteps(int n){
    if(n <= 1){
        return 0;
    }
    int x = minSteps(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%3 == 0){
        y = minSteps(n / 3);
    }
    if(n % 2 == 0){
        z = minSteps(n / 2);
    }
    int ans = min(x, min(y, z));
    return ans + 1;
}

/*
Using Memoization technique
*/

int minStepsBetter(int *ans, int n){
    if(n <= 1){
        ans[n] = 0;
        return 0;
    }
     ans[n - 1] = minStepsBetter(ans, n - 1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2 == 0){
        if(ans[n/2] == -1){
            ans[n / 2] = minStepsBetter(ans, n / 2);
        }
        y = ans[n / 2];
    }
    if(n % 3 == 0){
        if(ans[n/3] == 0){
            ans[n / 3] = minStepsBetter(ans, n / 3);
        }
        z = ans[n / 3];
    }

    ans[n] = min(ans[n - 1], min(y, z)) + 1;
    return ans[n];
}

int minStepsBetter(int n){
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    return minStepsBetter(ans, n);
}

// Min steps uisng Dynamic Programming

int minStepsDP(int n){
    int *ans = new int[n + 1];
    ans[1] = 0;
    for (int i = 2; i <= n; i++){
        ans[i] = 1 + ans[i - 1];
        if(i % 3 == 0){
            ans[i] = min(ans[i], 1 + ans[i / 3]);
        }
        if(i % 2 == 0){
            ans[i] = min(ans[i], 1 + ans[i / 2]);
        }
    }
    return ans[n];
}

int minCostPath(int ** input, int m ,int n, int i, int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }

    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n){
    return minCostPath(input, m, n, 0, 0);
}

int minCostPathBetter(int **input, int m, int n , int i, int j, int **ans){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }
    if(ans[i][j] != -1){
        return ans[i][j];
    }

    int x = minCostPathBetter(input, m, n, i, j + 1, ans);
    if(x < INT_MAX){
        ans[i][j + 1] = x;
    }

    int y = minCostPathBetter(input, m, n, i + 1, j + 1, ans);
    if(y < INT_MAX){
        ans[i + 1][j + 1] = y;
    }
    int z = minCostPathBetter(input, m, n, i + 1, j, ans);
    if(z < INT_MAX){
        ans[i + 1][j] = z;
    }
    ans[i][j] = min(x, min(y, z)) + input[i][j];
    return ans[i][j];
}

int minCostPathBetter(int **input, int m, int n){
    int **ans = new int *[m];
    for (int i = 0; i < m; i++){
        ans[i] = new int[n];
        for (int j = 0; i < n; j++){
            ans[i][j] = -1;
        }
    }
    return minCostPathBetter(input, m, n, 0, 0, ans);
}

/*
Min cost path using Dynamic Programming 
The complexity of this function is order of m*n;
*/

int minCostPathDp(int **input, int m ,int n){
    int **ans = new int *[m];
    for (int i = 0; i < m; i++){
        ans[i] = new int[n];
    }

    ans[m - 1][n - 1] = input[m - 1][n - 1];

    // Last Row

    for (int i = n - 2; i >= 0; i--){
        ans[m - 1][i] = input[m - 1][i] + ans[m - 1][i + 1];
    }

    // Last Column

    for (int i = m - 2; i >= 0; i--){
        ans[i][n - 1] = input[i][n - 1] + ans[i + 1][n - 1];
    }

    // Fill the  Remaining Array

    for (int i = m - 2; i >= 0; i--){
        for (int j = n - 2; j >= 0; j--){
            ans[i][j] = input[i][j] + min(ans[i][j + 1], min(ans[i + 1][j + 1], ans[i + 1][j]));
        }
    }
    return ans[0][0];
}

int main(){
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++){
        input[i] = new int[n];
        for (int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }
    // cout <<"Dp " <<  minCostPathDp(input, m, n) << endl;
    // cout <<"Recursion " << minCostPath(input, m, n) << endl;
    cout <<"Memoization " << minCostPathBetter(input, m, n) << endl;

    /*
    cout << minStepsDP(n) << endl;
    cout << minStepsBetter(n) << endl;
    cout << minSteps(n) << endl;

    cout << fiboBetter(n) << endl;
    cout << fibonacciNumber(n) << endl;
    cout << fibo(n) << endl;
*/
}