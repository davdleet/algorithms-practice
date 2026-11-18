#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<pair<char, int>>> arr;
vector<pair<char, int>> temp;
vector<int> visited;
vector<string> results;
string s;
string strn = "";
string ans = "";
bool mysort(pair<char, int> a, pair<char, int> b)
{
    if (a.first > b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        char max_a = ' ';
        char max_b = ' ';

        for (int i = 0; i < arr[a.second].size(); i++)
        {
            if (arr[a.second][i].first > max_a)
            {
                max_a = arr[a.second][i].first;
            }
        }

        for (int i = 0; i < arr[b.second].size(); i++)
        {
            if (arr[b.second][i].first > max_b)
            {
                max_b = arr[b.second][i].first;
            }
        }
        return max_a > max_b;
    }
    else
    {
        return false;
    }
}

void DFS(int node)
{
    visited[node] = true;
    strn = strn + s[node];
    bool visit = false;
    // first connection sorted by alphabetical order
    int next;
    for (int i = 0; i < arr[node].size(); i++)
    {
        next = arr[node][i].second;
        if (visited[next])
        {
            continue;
        }
        DFS(next);
        strn = strn.substr(0, strn.size() - 1);
        visit = true;
        if (i != arr[node].size() - 1 && arr[node][i + 1].first != arr[node][i].first)
        {
            break;
        }
    }
    if (!visit)
    {
        if (strn > ans)
        {
            ans = strn;
        }
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("E.txt", "rt", stdin);
    int N;
    cin >> N;
    arr = vector<vector<pair<char, int>>>(N + 1, temp);
    visited = vector<int>(N + 1, 0);
    cin >> s;
    s = " " + s;
    for (int i = 0; i < N; i++)
    {
        int u, v;
        cin >> u >> v;

        arr[u].push_back({s[v], v});
        arr[v].push_back({s[u], u});
    }
    for (int i = N; i >= 1; i--)
    {
        if (arr[i].size())
        {
            sort(arr[i].begin(), arr[i].end(), mysort);
        }
    }

    DFS(1);
    // sort(results.begin(), results.end());
    // cout << results[results.size() - 1];
    cout << ans;
}