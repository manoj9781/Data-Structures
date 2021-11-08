#include<iostream>
using namespace std;

void removeX(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != 'x'){
        removeX(s + 1);
    }else{
        int i = 1;
        for (; s[i] != '\0';i++){
            s[i - 1] = s[i];
        }
        s[i - 1] = '\0';
        removeX(s);
    }
}

int length(char s[]){
    if(s[0] == '\0'){
        return 0;
    }
    int ans = length(s + 1);
    return ans + 1;
}

int main(){
    char str[100];
    cin >> str;
    cout << length(str);
    removeX(str);
    cout <<'\n'<< str << endl;
    cout << length(str);

}