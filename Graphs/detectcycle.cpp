#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int start, bool *visited, bool *pathVisited, vector<int> adj[]){
    visited[start] = true;
    pathVisited[start] = true;

    for(auto it : adj[start]){
        if(! visited[it]){
            if(dfs(it, visited, pathVisited, adj) == true){
                return true;
            }
            else if(pathVisited[it]){
                return true;
            }
        }
    }
    pathVisited[start] = false;
    return false;
}
bool detectCycle(int n, vector<int> adj[]){
    bool *visited = new bool[n];
    bool *pathVisited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
        pathVisited[i] = false;
    }

    for (int i = 0; i < n; i++){
        if(!visited[i]){
           if(dfs(i, visited, pathVisited, adj) == true){
               return true;
           }
        }
    }
    return false;
}