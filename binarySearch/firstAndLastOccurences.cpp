#include <iostream>
using namespace std;


int firstOccurences(int *input, int n, int key){
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(input[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(input[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int lastOccurences(int *input, int n, int key){
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(input[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if(input[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int totalOccurences(int *input, int n, int key){
    int first = firstOccurences(input, n, key);
    int last = lastOccurences(input, n, key);
    return (last - first) + 1;
}


int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int *input = new int[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << "Enter Elements for search" << endl;
    int key;
    cin >> key;
    int ans = firstOccurences(input, n, key);
    cout << "First Occurences of the elements is " << ans << endl;
    ans = lastOccurences(input, n, key);
    cout << "Last Occurences of the elements is " << ans << endl;
    ans = totalOccurences(input, n, key);
    cout << "Total number Occurences of the elements is " << ans << endl;
    
}