#include <bits/stdc++,h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj(n+1, 0);

    for(int i = 0; i < edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
}