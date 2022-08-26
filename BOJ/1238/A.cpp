#include <iostream>
#include <queue>
using namespace std;

int N, M, X;
vector<int> dis;
vector<pair<int, int>> temp_arr;
vector<vector<pair<int, int>>> arr;
int dijkstra(int start, int target)
{
    if (start == target)
    {
        return 0;
    }
    dis = vector<int>(N + 1, 100000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (pq.size())
    {
        pair<int, int> current = pq.top();
        pq.pop();
        int c_cost = current.first;
        int c_node = current.second;
        if (c_cost > dis[c_node])
        {
            continue;
        }
        for (int i = 0; i < arr[c_node].size(); i++)
        {
            int cost = c_cost + arr[c_node][i].first;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M >> X;
    arr = vector<vector<pair<int, int>>>(N + 1, temp_arr);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({c, b});
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int go = dijkstra(i, X);
        int back = dijkstra(X, i);
        int total = go + back;
        ans = max(ans, total);
    }
    cout << ans;
}