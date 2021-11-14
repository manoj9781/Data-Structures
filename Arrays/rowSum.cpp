#include<iostream>
#include<climits>
using namespace std;

void findLargest(int **input, int m, int n){
    int maxSum = INT_MIN;
    int index = -1;
    bool isRow = false;

    for (int i = 0; i < m; i++){
        int rowSum = 0;
        for (int j = 0; j < n; j++){
            rowSum += input[i][j];
        }
        if(maxSum < rowSum){
            maxSum = rowSum;
            index = i;
        }
    }
    for (int j = 0; j < n; j++){
        int colSum = 0;
        for (int i = 0; i < m; i++){
            colSum += input[j][i];
        }
        if(maxSum < colSum){
            maxSum = colSum;
            index = j;
            isRow = false;
        }
    }
    if(isRow){
        cout << "Row " << endl;
    }
    else{
        cout << "Column " << endl;
    }
    cout << "Index " << index << " MaxSum " << maxSum << endl;
}

int main(){
    int m;
    int n;
    cout << "Enter number of rows" << endl;
    cin >> m;
    cout << "Enter Number of columns" << endl;
    cin >> n;
    int **input = new int*[m];
    for (int i = 0; i < m; i++){
        input[i] = new int[n];
        for (int j = 0; j < n; j++){
            input[i][j] = 0;
        }
    }
    cout << "Enter Elements " << endl;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n;j++){
            cin >> input[i][j];
        }
    }
    findLargest(input, m, n);

}