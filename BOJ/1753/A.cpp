#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Compare
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};

int V, E, S;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
vector<vector<pair<int, int>>> arr;
vector<int> dis;

void dijkstra(int vertex, int edge)
{
    pq.push({edge, vertex});
    while (pq.size())
    {
        int v, e;
        // distance to v
        e = pq.top().first;
        // vertex v
        v = pq.top().second;
        pq.pop();
        for (int i = 0; i < arr[v].size(); i++)
        {
            int v1, e1;
            e1 = arr[v][i].first;
            v1 = arr[v][i].second;
            if (e + e1 < dis[v1])
            {
                dis[v1] = e + e1;
                pq.push({e + e1, v1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> V >> E;

    cin >> S;

    arr = vector<vector<pair<int, int>>>(V + 1);
    dis = vector<int>(V + 1, 1e9);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({w, v});
    }
    dijkstra(S, 0);
    dis[S] = 0;
    for (int i = 1; i < V + 1; i++)
    {
        int num = dis[i];
        if (num == 1e9)
        {
            cout << "INF"
                 << "\n";
        }
        else
        {
            cout << num << "\n";
        }
    }
}