#include<iostream>
using namespace std;

void print(int **edges, int n, int startVertex, bool *visited){
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
            print(edges, n, i, visited);
        }
    }
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

    print(edges, n, 0, visited);
}