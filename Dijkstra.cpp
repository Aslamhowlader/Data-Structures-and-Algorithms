#include <bits/stdc++.h>
using namespace std;


void Dijkstra(int src, int n, vector<pair<int, int>> adj[])
{
    vector<int> dist(n, INT_MAX); 
    dist[src] = 0;

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue; 

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " : ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main()
{
    int n = 5; 
    vector<pair<int, int>> adj[n];

    

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});

    

    int source = 0; 
    Dijkstra(source, n, adj);

    return 0;
}
