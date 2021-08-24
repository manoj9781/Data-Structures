/*

Topic - Prism Algorithm
Author - Manoj Singh Rana
email - manojsinghrana467@gmail.com
TIME - 24/08/2021

*/

#include<iostream>
#include<climits>

using namespace std;

int main(){
    cout << "Enter Number of vertices and Number of Edges" << endl;
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++){
        int source, dest, weight;
        cin >> source >> dest >> weight;
        edges[source][dest] = weight;
        edges[dest][source] = weight;
    }

    cout << endl;
    prism(edges, n);

    for (int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}
