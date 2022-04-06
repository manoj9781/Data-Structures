#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int startVertex, bool *visited)
{
    cout << startVertex << endl;
    visited[startVertex] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == startVertex)
        {
            continue;
        }
        if (edges[startVertex][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int startingVertex, bool *visited)
{
    queue<int> pendingVertex;
    //  bool *visited = new bool[n];
    //  for (int i = 0; i < n; i++){
    //      visited[i] = false;
    //  }
    pendingVertex.push(startingVertex);
    visited[startingVertex] = true;
    while (pendingVertex.size() != 0)
    {
        int currentVertex = pendingVertex.front();
        pendingVertex.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == startingVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
    //  delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

bool hasPath(int **edges, int n, int src, int dest, bool *visited)
{
    if (src == dest)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == dest)
        {
            continue;
        }
        if (edges[i][dest] == 1)
        {
            if (!visited[i])
            {
                visited[i] = true;
                bool ans = hasPath(edges, n, i, dest, visited);
                if (ans == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool hasPath(int **edges, int n, int src, int dest)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    return hasPath(edges, n, src, dest, visited);
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int firstVertex;
        int secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // cout << "DFS" << endl;
    // printDFS(edges, n, 0, visited);
    // cout << "BFS" << endl;
    // printBFS(edges, n, 0);

    cout << "DFS" << endl;
    DFS(edges, n);
    // cout << "BFS" << endl;
    // BFS(edges, n);

    // cout << hasPath(edges, n, 1, 2) << endl;

    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}


/*

Topic - kurshkal's Algorithm
Author - Manoj Singh Rana
Email - manojsinghrana467@gmail.com
Time - 23/08/2021

// */

// #include<iostream>
// #include<algorithm>
// using namespace std;

// class Edge{
//     public:
//         int source;
//         int dest;
//         int weight;
// };

// bool compare(Edge e1, Edge e2){
//     return e1.weight < e2.weight;
// }

// int findParent(int v, int *parent){
//     if(parent[v] == v){
//         return v;
//     }
//     return findParent(parent[v], parent);
// }

// void krushkal(Edge *input, int n, int E){
//     sort(input, input + E, compare);
//     int *parent = new int[n];
//     for (int i = 0; i < n; i++){
//         parent[i] = i;
//     }

//     Edge *output = new Edge[n - 1];
//     int count = 0;
//     int i = 0;
//     while(count != n-1){
//         Edge currentEdge = input[i];

//         int sourceParent = findParent(currentEdge.source, parent);
//         int destParent = findParent(currentEdge.dest, parent);

//         if(sourceParent != destParent){
//             output[count] = currentEdge;
//             count++;
//             parent[sourceParent] = destParent;
//         }
//         i++;
//     }
//     for (int i = 0; i < n - 1; i++){
//         if(output[i].source < output[i].dest){
//             cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
//         }
//         else{
//             cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
//         }
//     }
// }

// int main(){
//     int n, E;
//     cin >> n >> E;
//     Edge *input = new Edge[E];
//     for (int i = 0; i < E; i++){
//         int s, d, w;
//         cin >> s >> d >> w;
//         input[i].source = s;
//         input[i].dest = d;
//         input[i].weight = w;
//     }

//     krushkal(input, n, E);
// }