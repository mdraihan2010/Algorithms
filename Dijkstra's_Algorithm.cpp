#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, vector<pair<int, int>> adj[], int n, vector<int> &result)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for (int i = 0; i < adj[node].size(); i++)
        {
            int nextNode = adj[node][i].first;
            int weight = adj[node][i].second;
            if (distance + weight < dist[nextNode])
            {
                dist[nextNode] = distance + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    result = dist;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;
    vector<int> result;
    dijkstra(source, adj, n, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}