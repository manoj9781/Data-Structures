#include <iostream>
using namespace std;

void sayDigit(string input[], int n){
    if(n == 0){
        return;
    }
    int digit = n % 10;
    n = n / 10;
    sayDigit(input, n);
    cout << input[digit] << " ";

}

int main()
{
    string input[10] = {"zero", "one", "Two", "Three", "four", "five", "six", "seven", "Eight", "Nine"};
    cout << "Enter Number" << endl;
    int n;
    cin >> n;
    sayDigit(input, n);
}