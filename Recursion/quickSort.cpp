#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int input[], int start, int end)
{
    int pivot = input[0];
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (input[i] < pivot)
        {
            count++;
        }
    }
    int PI = start + count;
    swap(input[start], input[PI]);
    int i = start;
    int j = end;
    while (i < PI && j > PI)
    {
        if (input[i] < input[PI])
        {
            i++;
        }
        else if (input[j] >= input[PI])
        {
            j--;
        }
        else
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
    return PI;
}

void quickSort(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int index = partition(input, start, end);
    quickSort(input, start, index - 1);
    quickSort(input, index + 1, end);
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
    quickSort(input, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}