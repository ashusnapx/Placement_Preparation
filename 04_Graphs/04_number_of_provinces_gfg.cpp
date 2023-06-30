void dfs(int node, vector<int> adj[], int *visited)
{
    visited[node] = 1;
    for(auto it: adj[node])
    {
        if(visited[it] == 0)
        {
            dfs(it, adj, visited);
        }
    }
}
int numProvinces(vector<vector<int>>& adj, int number_of_vertices) 
{
    /* convert adjacency matrix to list */
    vector<int> adjacency_list[number_of_vertices];
    for(int i = 0; i < number_of_vertices; i++)
    {
        for(int j = 0; j < number_of_vertices; j++)
        {
            if(adj[i][j] == 1 and i != j)
            {
                adjacency_list[i].push_back(j);
                adjacency_list[j].push_back(i);
            }
        }
    }

    int visited[number_of_vertices] = {0};
    int province_counter = 0;
    for(int i = 0; i < number_of_vertices; i++)
    {
        if(visited[i] == 0)
        {
            ++province_counter;
            dfs(i, adjacency_list, visited);
        }
    }
    return province_counter;
}
