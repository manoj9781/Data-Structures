#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int i, vector<int> adj[], bool *visited)
{

    queue<int> pendingNodes;
    pendingNodes.push(i);
    visited[i] = true;
    while (pendingNodes.size() != 0)
    {
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout << front << " ";
        for (auto it : adj[front])
        {
            if (!visited[it])
            {
                pendingNodes.push(it);
                visited[it] = true;
            }
        }
    }
}

void bfs(int n, vector<int> adj[])
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(n, i, adj, visited);
        }
    }
    cout << endl;
    delete[] visited;
}

/* DFS Algorithm */

void dfs(int startVertex, vector<int> adj[], bool *visited){
    cout << startVertex << " ";
    visited[startVertex] = true;
    for(auto it : adj[startVertex]){
        if(!visited[it]){
            dfs(it, adj, visited);
        }
    }
}

void dfs(int n, vector<int> adj[]){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
    cout << endl;
    delete[] visited;
}

int main()
{
    int n;
    int E;
    cin >> n >> E;
    vector<int> adj[n];
    for (int i = 0; i < E; i++)
    {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        adj[firstVertex].push_back(secondVertex);
        adj[secondVertex].push_back(firstVertex);
    }
    cout << "BFS" << endl;
    bfs(n, adj);
    cout << "DFS" << endl;
    dfs(n, adj);
    return 0;
}