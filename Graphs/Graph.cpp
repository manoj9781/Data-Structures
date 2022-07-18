#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int E;
    cin >> n >> E;
    vector<int> adj[n];
    for (int i = 0; i < E; i++){
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        adj[firstVertex].push_back(secondVertex);
        adj[secondVertex].push_back(firstVertex);
    }
    return 0;
}