#include <iostream>
using namespace std;
int main()
{
    int input[3][3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin >> input[i][j][k];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << "After Adding last two digit of reg. no ";
                cout << input[i][j][k] + 76 << " ";
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
