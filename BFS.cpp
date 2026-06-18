#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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
    BFS(start, adj, visited, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}