#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int S, E;

vector<vector<pair<long long, int>>> bus;
vector<pair<long long, int>> t1;
vector<long long> d;

int dijkstra()
{
    d[S] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, S});
    while (pq.size())
    {
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (d[node] < cost)
        {
            continue;
        }
        for (int i = 0; i < bus[node].size(); i++)
        {
            long long c = bus[node][i].first;
            int n = bus[node][i].second;
            if (d[n] > d[node] + c)
            {
                d[n] = d[node] + c;
                pq.push({d[node] + c, n});
            }
        }
    }
    return d[E];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    bus = vector<vector<pair<long long, int>>>(N + 1, t1);
    d = vector<long long>(N + 1, 100000000000000);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        bus[a].push_back({c, b});
    }
    cin >> S >> E;
    cout << dijkstra();
}