#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> arr;
vector<pair<int, int>> temp;
vector<int> visited;
int N;
pair<int, int> DFS(int node, int cost)
{
    visited[node] = true;
    int furthest_node = node;
    int furthest_cost = cost;
    for (int i = 0; i < arr[node].size(); i++)
    {
        int connected = arr[node][i].first;
        int c_cost = arr[node][i].second;
        if (visited[connected])
        {
            continue;
        }
        pair<int, int> result = DFS(connected, cost + c_cost);
        if (result.second > furthest_cost)
        {
            furthest_node = result.first;
            furthest_cost = result.second;
        }
    }
    return {furthest_node, furthest_cost};
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    arr = vector<vector<pair<int, int>>>(N + 1, temp);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    visited = vector<int>(N + 1, 0);
    // start from node 1 (select any)
    pair<int, int> first = DFS(1, 0);
    visited = vector<int>(N + 1, 0);
    pair<int, int> second = DFS(first.first, 0);
    cout << second.second;
}