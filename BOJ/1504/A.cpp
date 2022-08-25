#include <iostream>
#include <queue>
using namespace std;

// first is cost, second is node
vector<vector<pair<long long, int>>> arr;
vector<pair<long long, int>> temp;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<long long> dis;
vector<int> visited;
int N, E;

int dijkstra(int start, int target)
{
    if (start == target)
    {
        return 0;
    }
    pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>();
    dis = vector<long long>(N + 1, 1000000000);
    visited = vector<int>(N + 1, 0);
    pq.push({0, start});
    while (pq.size())
    {
        pair<long long, int> current = pq.top();
        pq.pop();
        long long c_cost = current.first;
        int c_node = current.second;
        if (c_cost > dis[c_node])
        {
            continue;
        }
        for (int i = 0; i < arr[c_node].size(); i++)
        {
            // cost from start to next connected node is cost to current node + cost to next node
            long long cost = c_cost + arr[c_node][i].first;
            int connected = arr[c_node][i].second;
            if (cost < dis[connected])
            {
                dis[connected] = cost;
                pq.push({cost, connected});
            }
        }
    }
    return dis[target];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> E;
    arr = vector<vector<pair<long long, int>>>(N + 1, temp);
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({c, b});
        arr[b].push_back({c, a});
    }
    int v1, v2;
    cin >> v1 >> v2;
    // two routes are possible
    // 1. 1 -> v1 -> v2 -> N
    // 2. 1 -> v2 -> v1 -> N

    // calculate first path
    long long p1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    // calculate second path
    long long p2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    long long ans = min(p1, p2);
    if (ans >= 1000000000 || ans < 0)
    {
        ans = -1;
    }
    cout << ans;
}