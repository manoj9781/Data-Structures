#include<iostream>
using namespace std;
void sort(int input[], int size){
    if(size == 0){
        return;
    }

    int zeros = 0, one = 0, two = 0;
    for (int i = 0; i < size; i++){
        if(input[i] == 0){
            zeros++;
        }
        else if(input[i] == 1){
            one++;
        }
        else if(input[i] == 2){
            two++;
        }
    }
    int j = 0;
    while(zeros--){
        input[j] = 0;
        j++;
    }
    while(one--){
        input[j] = 1;
        j++;
    }
    while(two--){
        input[j] = 2;
        j++;
    }
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }

    sort(input, n);
    for (int i = 0; i < n;i++){
        cout << input[i] << " ";
    }
    cout << endl;
}