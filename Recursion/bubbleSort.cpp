
#include<iostream>
using namespace std;


void sortArray(int input[], int n){
    if(n == 0 || n == 1){
        return;
    }
    for (int i = 0; i < n - 1; i++){
        if(input[i] > input[i+1]){
            swap(input[i], input[i + 1]);
        }
    }
    sortArray(input, n - 1);
}

int main(){
    int n;
    cin >> n;
    int input[100];
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    sortArray(input, n);
  for (int i = 0; i < n; i++){
        cout << input[i]<< " ";
    }
    cout << endl;
}
