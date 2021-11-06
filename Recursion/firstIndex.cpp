#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int k){
    if(size == 0){
        return -1;
    }
    if(input[0] == k){
        return 0;
    }
    int ans = firstIndex(input + 1, size - 1, k);
    if(ans == -1){
        return -1;
    }
    
    else{
        return ans+ 1;
    }
}

int lastIndex(int input[], int size, int x){
    if(size == 0){
        return -1;
    }

    int ans = lastIndex(input + 1, size - 1, x);
    if(ans != -1){
        return ans + 1;
    }
    if(input[0] == x){
        return 0;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int *input = new int[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    // cout << firstIndex(input, n, 5) << endl;
    cout << "Enter elements for search" << endl;
    int k;
    cin >> k;
    cout << lastIndex(input, n, k) << endl;
}