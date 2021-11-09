#include<iostream>
using namespace std;

void mergeSort(int input[], int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end - start + 1];

    while(i <= mid && j <= end){
        if(input[i] < input[j]){
            temp[k] = input[i];
            k++;
            i++;
        }
        else{
            temp[k] = input[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        temp[k] = input[i];
        i++;
        k++;
    }
    while(j <= end){
        temp[k] = input[j];
        k++;
        j++;
    }
    for (int l = start; l <= end; l++){
        input[l] = temp[l - start];
    }
}

void mergeSort(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    mergeSort(input, start, mid, end);
}

void mergeSort(int input[], int size){
    mergeSort(input, 0, size - 1);
}

int main(){
    int n;
    cout << "Enter Number of elements" << endl;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << "Before merge Sort" << endl;
    for (int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    cout << "\nAfter Merge Sort" << endl;
    mergeSort(input, n);
     for (int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}