#include <iostream>
using namespace std;

// For connected Graphs
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
        if (edges[startVertex][i] == 1 && !visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
}

#include <queue>
// for connected Graphs
void PrintBFS(int **edges, int n, int startVertex)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    visited[startVertex] = true;
    while (pendingVertices.size() != 0)
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] == true;
            }
        }
    }
    delete[] visited;
}

/*

BFS and DFS for disconnected graphs

*/

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
            count++;
        }
    }
}

void printBFS(int **edges, int n, int startVertex, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    visited[startVertex] = true;
    while (pendingVertices.size() != 0)
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
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
        if (edges[dest][i] == 1 && !visited[i])
        {
            visited[i] = true;
            bool ans = hasPath(edges, n, i, dest, visited);
            if (ans == true)
            {
                return true;
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

bool detectCycle(int **edges, int n, int s, bool *visited)
{
    queue<pair<int, int>> pendingNodes;

    visited[s] = true;
    pendingNodes.push({s, -1});

    while (pendingNodes.size() != 0)
    {
        int currentNode = pendingNodes.front().first;
        int previous = pendingNodes.front().second;

        pendingNodes.pop();

        for (int i = 0; i < n; i++)
        {
            if (edges[i][currentNode] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingNodes.push({i, currentNode});
            }
            else if (previous != i)
            {
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(int **edges, int n)
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
            if (detectCycle(edges, n, i, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    int e;
    cout << "Enter number of vertices" << endl;
    cin >> n;
    cout << "Enter number of Edges" << endl;
    cin >> e;

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
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    cout << detectCycle(edges, n) << "\n";

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // cout << "DFS" << endl;
    // printDFS(edges, n, 0, visited);
    // cout << "BFS" << endl;
    // PrintBFS(edges, n, 0);
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}