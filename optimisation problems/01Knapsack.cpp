#include <bits/stdc++.h>

using namespace std;

int zero_one_knapsack(vector<pair<int,int>>& v, int c, int n)
{
    int k[n+1][c+1];
    int p, w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i==0 || j==0)
            {
                k[i][j] = 0;
                continue;
            }

            p = v[i-1].first;
            w = v[i-1].second;

            if (w > j)
                k[i][j] = k[i-1][j];
            else
                k[i][j] = max(k[i-1][j-w] + p, k[i-1][j]);
        }
    }
    return k[n][c];
}

int main(void)
{
    int c;
    cout << "Enter the capacity of the knapsack: ";
    cin >> c;
    vector<pair<int,int>> v;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int p,w;
    while (n--)
    {
        cin >> p >> w;
        v.push_back(make_pair(p,w));
    }

    cout << "Profit: " << zero_one_knapsack(v, c, v.size()) << endl;

    return 0;
}

