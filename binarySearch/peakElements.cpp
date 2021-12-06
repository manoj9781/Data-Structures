#include <iostream>
using namespace std;

int peakElement(int *input, int n){
    int start = 0;
    int end = n - 1;
     int mid = (end + start) / 2;
    while(start < end){
       
        if(input[mid] < input[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
         mid = (end + start) / 2;
    }
    return input[start];
}

int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int *input = new int[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int ans = peakElement(input, n);
    cout << "Peak element of the Array is " << ans << endl;

}