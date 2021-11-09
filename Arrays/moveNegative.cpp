#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rearrange(int input[], int size)
{
    if (size == 0)
    {
        return;
    }
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] < 0)
        {
            if (i != j)
            {
                swap(input[i], input[j]);
            }
            j++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    rearrange(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}