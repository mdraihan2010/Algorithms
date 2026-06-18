#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int n, vector<vector<int>> &edges, int source, vector<int> &result)
{
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool negativeCycle = false;

    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v])
        {
            negativeCycle = true;
        }
    }
    if (negativeCycle)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        result = dist;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;
    vector<int> result;
    bellmanFord(n, edges, source, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}