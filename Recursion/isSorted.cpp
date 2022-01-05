#include <iostream>
using namespace std;

bool isSorted(int input[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (input[0] > input[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(input + 1, n - 1);
        return ans;
    }
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
    bool ans = isSorted(input, n);
    if (ans)
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }
}