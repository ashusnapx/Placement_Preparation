#include <bits/stdc++.h> 
vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    // create a visited array and mark everything as 0
    int visited[V] = {0};

    // make the first element of visited array as 1
    visited[0] = 1;

    // create a queue to store value of each root at each level
    queue<int> q;

    // push the visited elements once in the queue
    q.push(0);

    vector<int> ans;

    // traverse the whole queue until it becomes empty
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // traverse adjancency list to check whether the node was present previously
        for(auto it: adj[node])
        {
            // if not visited
            if(!visited[it])
            {
                // then make it visited by replacing 0 by 1
                visited[it] = 1;

                // and also add them in the queue
                q.push(it);
            }
        }
    }

    return ans;
}

// Degree = number of neighbour nodes
// Time complexity  : O(Number of nodes) + O(2 x Edges)
// Space complexity : O(3N) ~ O(N)