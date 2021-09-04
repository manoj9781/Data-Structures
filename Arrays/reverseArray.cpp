#include<iostream>
using namespace std;

void arrayReverse(int a[], int n){
    int i = 0;
    int j = n - 1;
    while(i < j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
int main(){
    int n;
    cout << "Enter number of Elements" << endl;
    cin >> n;
    int input[100];
    cout << "Enter Elements" << endl;
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << "Array After reverse" << endl;
    arrayReverse(input, n);
    for (int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}