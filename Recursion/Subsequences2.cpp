#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printSubsequences(int index, vector<int> &ans, int input[], int n)
{
    if (index == n)
    {
        if (ans.size() == 0)
        {
            cout << "{}";
        }
        for (auto it : ans)
        {

            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(input[index]);
    printSubsequences(index + 1, ans, input, n);
    ans.pop_back();
    printSubsequences(index + 1, ans, input, n);
}

int main()
{
    int n;
    cout << "Enter Number of Elements " << endl;
    cin >> n;
    int *input = new int[n];

    cout << "Enter Elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> ans;
    cout << "SubSequences of the Array" << endl;
    printSubsequences(0, ans, input, n);
}