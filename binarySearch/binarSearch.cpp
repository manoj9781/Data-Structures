#include<iostream>
using namespace std;


int binarySearch(int *input, int n, int key){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(input[mid] == key){
            return mid;
        }
        else if(input[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
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
    int key;
    cout << "Enter key for serach" << endl;
    cin >> key;
    int index = binarySearch(input, n, key);
    cout << "Index of " << key << " is " << index << endl;
}