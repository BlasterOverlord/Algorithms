#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> key;
vector<int> parent;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
vector<int> explored;

void Prim(int n, int r)
{
    key.resize(n+1, 1e7);
    parent.resize(n+1, -1);
    explored.resize(n+1, false);
    key[r] = 0;
    q.push(make_pair(key[r], r));

    int u,v,w;
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        explored[u] = true;

        for (int j = 0; j < adj[u].size(); j++)
        {
            w = adj[u][j].second;
            v = adj[u][j].first;

            if (!explored[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
                q.push(make_pair(key[v], v));
            }
        }
    }
}

int main(void)
{
    int n,e;
    cin >> n >> e;

    adj.resize(n+1);

    int nodeA, nodeB, w;

    for (int i = 0; i < e; i++)
    {
        cin >> nodeA >> nodeB >> w;
        adj[nodeA].push_back(make_pair(nodeB,w));
        adj[nodeB].push_back(make_pair(nodeA,w));
    }

    Prim(n,1);

    int totalWeight = 0;
    cout << "Minimum Spanning Tree:\n";
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] > 0)
        {
            cout << parent[i] << " - " << i << endl;
            totalWeight += key[i];
        }
    }
    cout << "Total Weight: " << totalWeight;

    return 0;
}

/*
8 10
1 2 14
1 8 3
2 3 6
2 4 5
2 8 10
3 4 4
4 5 9
4 7 2
6 7 15
7 8 8
*/
