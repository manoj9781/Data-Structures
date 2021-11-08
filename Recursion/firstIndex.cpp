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

int allIndex(int input[], int size, int x, int output[]){
    if(size == 0){
        return -1;
    }
    int smallOutput = allIndex(input + 1, size - 1, x, output);
    if(input[0] == x){
        for (int i = smallOutput - 1; i >= 0; i--){
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        smallOutput++;
    }
    else{
        for (int i = smallOutput; i >= 0; i--){
            output[i] = output[i] + 1;
        }
        return smallOutput;
    }
}

int countZeros(int n){
    if(n == 0){
        return 0;
    }
    if(n%10 ==0){
        return 1 + countZeros(n / 10);
    }
    return countZeros(n / 10);
}

int countZeros2(int n){
    int count = 0;
    while(n >= 0){
        int r = n % 10;
        if(r == 0){
            count++;
        }
        n = n / 10;
    }
    return count;
}

int main(){
    cout << countZeros(1000) << endl;
    cout << countZeros2(1000) << endl;
}

// int main(){
//     int n;
//     cout << "Enter number of elements" << endl;
//     cin >> n;
//     int *input = new int[n];
//     cout << "Enter elements" << endl;
//     for (int i = 0; i < n; i++){
//         cin >> input[i];
//     }
//     // cout << firstIndex(input, n, 5) << endl;
//     cout << "Enter element for search" << endl;
//     int k;
//     cin >> k;
//     // cout << lastIndex(input, n, k) << endl;
// }