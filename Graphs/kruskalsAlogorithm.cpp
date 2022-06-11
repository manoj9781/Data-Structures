#include<iostream>
#include<algorithm>
using namespace std;


class Edge{
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
    if(v == parent[v]){
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskal(Edge *input, int n, int E){
    // Sort the input array in ascending order 
    sort(input, input + E, compare);

    // Ouptut array for printing
    Edge *output = new Edge[n - 1];

    // Parent array initialize with own value
    int *parent = new int[n];
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;

    while(count != n-1){
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    cout << "Output " << endl;
    for (int i = 0; i < count; i++){
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
    }
    delete[] output;
    delete[] parent;
}

int main(){

    int n;
    int E;
    cin >> n >> E;
    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++){
        int source, dest, weight;
        cin >> source >> dest >> weight;
        input[i].source = source;
        input[i].dest = dest;
        input[i].weight = weight;
    }
    kruskal(input, n, E);

    delete[] input;
}