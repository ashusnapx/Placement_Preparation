/* 
n -> nodes
m -> edges
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // entire graph will be stored here
    int adj[nodes + 1][edges + 1];

    for(int i = 0; i < edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1; // because its an undirected graph
    }
}