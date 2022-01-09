#include<iostream>
#include<climits>
using namespace std;

int maxScore(int *input, int n){
    int sum = 0;
    int minElement = INT_MAX;
    for (int i = 0; i < n; i++){
        sum += input[i];
        if(input[i] < minElement){
            minElement = input[i];
        }
    }
    int ans = minElement * n;
    return ans + sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int input[100];
        for (int i = 0; i < n; i++){
            cin >> input[i];
        }
        int ans = maxScore(input, n);
        cout << ans << endl;
    }
}