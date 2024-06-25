#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<double,double>& a, const pair<double,double>& b)
{
    return (a.first/a.second) > (b.first/b.second);
}

double knapsack(double capacity, vector<pair<double,double>>& v)
{
    double profit = 0;
    sort(v.begin(), v.end(), compare);
    int i = 0;
    int n = v.size();
    double p,w;
    while (capacity>0 && i<n)
    {
        p = v[i].first;
        w = v[i].second;

        if (w > capacity)
            profit += (capacity/w)*p;
        else
            profit += p;

        capacity -= w;
        i++;
    }
    return profit;
}

int main(void)
{
    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    vector<pair<double,double>> v;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    double p,w;
    while (n--)
    {
        cin >> p >> w;
        v.push_back(make_pair(p,w));
    }

    cout << "Profit: " << knapsack(capacity, v) << endl;

    return 0;
}
