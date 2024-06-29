#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> path;

vector<vector<int>> lcs(int n, int m, string s1, string s2)
{
    vector<vector<int>> t(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else if (s1[i-1] == s2[j-1])
            {
                t[i][j] = t[i-1][j-1] + 1;
                path[i][j] = "diagonal";
            }
            else if (t[i-1][j] >= t[i][j-1])
            {
                t[i][j] = t[i-1][j];
                path[i][j] = "up";
            }
            else
            {
                t[i][j] = t[i][j-1];
                path[i][j] = "left";
            }
        }
    }
    return t;
}

void printLCS(string s, int i, int j)
{
    if (i==0 || j==0)
        return;

    if (path[i][j] == "diagonal")
    {
        printLCS(s, i-1, j-1);
        cout << s[i-1] << " ";
    }
    else if (path[i][j] == "up")
        printLCS(s,i-1,j);
    else
        printLCS(s, i, j-1);
}

int main(void)
{
    string s1,s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    int n = s1.size();
    int m = s2.size();

    path.resize(n+1, vector<string>(m+1));

    vector<vector<int>> t = lcs(n, m, s1, s2);

    cout << "LCS: " << t[n][m] << endl;
    printLCS(s1, n, m);

    return 0;
}

