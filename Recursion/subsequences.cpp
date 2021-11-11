#include<iostream>
using namespace std;

int subsequences(string input, string output[]){
    if(input.size() == 0){
        output[0] = " ";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOuptut = subsequences(smallString, output);
    for (int i = 0; i < smallOuptut; i++){
        output[i + smallOuptut] = input[0] + output[i];
    }
    return 2 * smallOuptut;
}

int main(){
    string input;
    cin >> input;
    string *output = new string[100];
    int count = subsequences(input, output);
    for (int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}