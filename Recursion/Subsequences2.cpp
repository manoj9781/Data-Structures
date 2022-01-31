#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Print All Subsequences of the Array
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

// Print All the Subsequences whose sum is equal to given sum

void printS(int index, vector<int> &ans, int s, int *input, int n, int sum)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }

        return;
    }
    ans.push_back(input[index]);
    s += input[index];
    printS(index + 1, ans, s, input, n, sum);
    ans.pop_back();
    s -= input[index];
    printS(index + 1, ans, s, input, n, sum);
}

// Print anyone subsuquences
bool printOne(int index, vector<int> &ans, int s, int *input, int n, int sum)
{
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(input[index]);
    s += input[index];
    if (printOne(index + 1, ans, s, input, n, sum) == true)
    {
        return true;
    }
    ans.pop_back();
    s -= input[index];
    if (printOne(index + 1, ans, s, input, n, sum) == true)
    {
        return true;
    }
    return false;
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
    int sum = 2;
    printOne(0, ans, 0, input, n, sum);
    // printS(0, ans, 0, input, n, sum);
    // cout << "SubSequences of the Array" << endl;
    // printSubsequences(0, ans, input, n);
}