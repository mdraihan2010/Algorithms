#include <bits/stdc++.h>
using namespace std;

void DFS(int node,
         vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbor = adj[node][i];
        if (!visited[neighbor])
        {
            DFS(neighbor, adj, visited, result);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    vector<int> result;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cin >> start;
    DFS(start, adj, visited, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}