#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int>>> edges; // {w, {u,v} }
vector<int> parent;
int totalWeight = 0;

int FindSet(int node)
{
    if (parent[node] == node)
        return node;

    return FindSet(parent[node]);
}

void Union(int u, int v)
{
    parent[v] = u;
}

vector<pair<int,int>> Kruskal(int n)
{
    vector<pair<int,int>> tree;

    //MakeSet(v)
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());

    int e = 0;
    int u,v,w;
    for (int i = 0; i < edges.size(); i++)
    {
        w = edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;

        if (e == n-1)
            break;

        if (FindSet(u) != FindSet(v))
        {
            e++;
            Union(FindSet(u), FindSet(v));
            totalWeight += w;
            tree.push_back(make_pair(u,v));
        }
    }
    return tree;
}

int main(void)
{
    int n,e;
    cin >> n >> e;

    edges.resize(n+1);
    parent.resize(n+1);

    int nodeA, nodeB, w;

    for (int i = 0; i < e; i++)
    {
        cin >> nodeA >> nodeB >> w;
        edges.push_back(make_pair(w, make_pair(nodeA,nodeB)));
    }

    vector<pair<int,int>> tree = Kruskal(n);

    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i].first << " - " << tree[i].second << endl;
    }

    cout << "\nTotal Weight: " << totalWeight << endl;

    return 0;
}

/*
7 11
1 2 2
1 6 14
1 7 8
2 3 19
2 6 25
3 4 9
3 5 5
3 6 17
4 5 1
5 6 13
6 7 21
*/
