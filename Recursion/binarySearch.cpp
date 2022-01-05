#include<iostream>
using namespace std;

int binarySearch(int input[], int start, int end, int key){
    if(start > end){
        return -1;
    }
    int mid = start + (end - start) / 2;
    if(input[mid] == key){
        return mid;
    }
    else if(input[mid] < key){
        return binarySearch(input, mid + 1, end, key);
    }
    else{
        return binarySearch(input, start, mid - 1, key);
    }

}

int binarySearch(int input[], int n, int key){
    return binarySearch(input, 0, n - 1, key);
}

int main()
{
    int n;
    cin >> n;
    int input[100];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int key;
    cin >> key;
    int ans = binarySearch(input, n, key);
    cout << "Key is Present at " << ans+ 1 << endl;
}