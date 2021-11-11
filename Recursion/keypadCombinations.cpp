#include<iostream>
using namespace std;

int keypad(int n, string output[], string dialer[]){

}

int keypad(int n, string output[]){
    string dialer[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad(n, output, dialer);
}

int main(){
    int n;
    cin >> n;
    string *output = new string[100];
    int count = keypad(n, output);
    for (int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}