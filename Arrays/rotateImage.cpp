#include <iostream>
using namespace std;

void rotate(int input[][3], int m, int n)
{

    int row = m;
    int column = n;
    for (int j = 0; j < column; j++)
    {
        for (int i = row-1; i >= 0; i--)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int input[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> input[i][j];
        }
    }

        rotate(input, 3, 3);
}