#include <iostream>
using namespace std;

int keypad(int num, string output[], string dialer[])
{
    if (num == 0)
    {
        output[0] = " "; 
        return 1;
    }
    int lastDigit = num % 10;
    int smallInput = num / 10;
    string smalloutput[100];
    int smallAns = keypad(smallInput, smalloutput, dialer);
    string op = dialer[lastDigit];
    int k = 0;
    for (int i = 0; i < op.size(); i++)
    {
        for (int j = 0; j < smallAns; j++)
        {
            output[k++] = smalloutput[j] + op[i];
        }
    }

    return k;
}

int keypad(int n, string output[])
{
    string dialer[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad(n, output, dialer);
}

int main()
{
    int n;
    cin >> n;
    string *output = new string[100];
    int count = keypad(n, output);
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}