#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> temp;
vector<vector<pair<int, int>>> arr;
vector<int> visited;

pair<int, int> DFS(int node, int cost)
{
    visited[node] = true;
    int furthest = node;
    int f_cost = 0;
    // select the furthest unvisited node
    for (int i = 0; i < arr[node].size(); i++)
    {
        if (visited[arr[node][i].second])
        {
            continue;
        }
        pair<int, int> temp = DFS(arr[node][i].second, arr[node][i].first);
        if (temp.second > f_cost)
        {
            furthest = temp.first;
            f_cost = temp.second;
        }
    }
    return {furthest, f_cost + cost};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    arr = vector<vector<pair<int, int>>>(N + 1, temp);
    visited = vector<int>(N + 1, 0);
    // initialize input
    for (int i = 0; i < N; i++)
    {
        int node;
        cin >> node;
        int connected;
        cin >> connected;
        while (connected != -1)
        {
            int cost;
            cin >> cost;
            arr[node].push_back({cost, connected});
            cin >> connected;
        }
    }
    // select node 1 as a starting point
    int start = 1;
    // find furthest from start
    pair<int, int> initial = DFS(1, 0);
    visited = vector<int>(N + 1, 0);
    pair<int, int> result = DFS(initial.first, 0);
    cout << result.second << endl;
}