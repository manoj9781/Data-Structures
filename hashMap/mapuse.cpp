#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string, int> ourmap;
    ourmap["M"] = 1000;
    cout << ourmap["M"] << endl;
}