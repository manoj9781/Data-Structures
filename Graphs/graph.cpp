#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edges, int n, int startVertex, bool *visited){
    cout << startVertex << endl;
    visited[startVertex] = true;

    for (int i = 0; i < n; i++){
        if(i == startVertex){
            continue;
        }
        if(edges[startVertex][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

 void printBFS(int **edges, int n, int startingVertex, bool *visited){
     queue<int> pendingVertex;
    //  bool *visited = new bool[n];
    //  for (int i = 0; i < n; i++){
    //      visited[i] = false;
    //  }
     pendingVertex.push(startingVertex);
     visited[startingVertex] = true;
     while(pendingVertex.size() != 0){
         int currentVertex = pendingVertex.front();
         pendingVertex.pop();
         cout << currentVertex << endl;
         for (int i = 0; i < n; i++){
             if(i == startingVertex){
                 continue;
             }
             if(edges[currentVertex][i] == 1 && !visited[i]){
                 pendingVertex.push(i);
                 visited[i] = true;
             }
         }
     }
    //  delete[] visited;
}

void BFS(int **edges, int n){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    for (int i = 0; i < n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

void DFS(int **edges, int n){
   bool *visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    for (int i = 0; i < n; i++){
        if(!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main(){
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++){
        int firstVertex;
        int secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    // cout << "DFS" << endl;
    // printDFS(edges, n, 0, visited);
    // cout << "BFS" << endl;
    // printBFS(edges, n, 0);

    cout << "DFS" << endl;
    DFS(edges, n);
    cout << "BFS" << endl;
    BFS(edges, n);

    delete[] visited;
    for (int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}