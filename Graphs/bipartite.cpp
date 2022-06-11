#include<bits/stdc++.h>
using namespace std;

bool bipartite(int source, vector<int> adj[], int *color){
    queue<int> pendingNodes;
    pendingNodes.push(source);
    color[source] = 1;
    while(pendingNodes.size() != 0){
        int front = pendingNodes.front();
        pendingNodes.pop();

        for(auto it : adj[front]){
            if(color[it] == -1){
                color[it] = 1 - color[front];
                pendingNodes.push(it);
            }
            else if(color[it] == color[front]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n){
    int *color = new int[n];
    for (int i = 0; i < n;i++){
        color[i] = -1;
    }
    for (int i = 0; i < n;i++){
        if(color[i] == -1){
            if(!bipartite(i, adj, color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, E;
    cout << "Enter number of vertices and number of edges\n";
    cin >> n >> E;
    vector<int> adj[n];
    for (int i = 0; i < E; i++){
        int source, dest;
        cin >> source >> dest;
        adj[source].push_back(dest);
        adj[dest].push_back(source);
    }
    for (int v = 0; v < E; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }

    if(checkBipartite(adj, n)){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }
   
}