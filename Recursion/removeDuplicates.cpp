#include<iostream>
using namespace std;

void removeDuplicates(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] == s[1]){
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
            s[i - 1] = s[i];
            removeDuplicates(s);
    }
    else{
        removeDuplicates(s + 1);
    }
   
}

int main(){

    char str[1000];
    cin >> str;
    removeDuplicates(str);
    cout << str << endl;
}