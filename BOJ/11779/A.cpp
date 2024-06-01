#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

struct bus_info
{
    int one;
    int two;
    int three;
};

struct compare_bus
{
    bool operator()(const bus_info &b1, const bus_info &b2)
    {
        return b1.three > b2.three;
    }
};

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> adj_matrix(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> dist(n + 1, INT_MAX);
    vector<int> route(n + 1, 0);
    priority_queue<bus_info, vector<bus_info>, compare_bus> pq;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj_matrix[a][b] > c)
            adj_matrix[a][b] = c;
    }
    int start, end;
    cin >> start;
    cin >> end;

    dist[start] = 0;
    pq.push({start, start, 0});
    while (pq.size())
    {
        bus_info current = pq.top();
        pq.pop();
        int a, b, c;
        a = current.one;
        b = current.two;
        c = current.three;
        if (dist[b] < c)
            continue;
        for (int i = 0; i < n + 1; i++)
        {
            if (adj_matrix[b][i] != INT_MAX)
            {
                if (dist[b] + adj_matrix[b][i] < dist[i])
                {
                    dist[i] = dist[b] + adj_matrix[b][i];
                    route[i] = b;
                    pq.push({b, i, dist[i]});
                }
            }
        }
    }

    cout << dist[end] << endl;
    vector<int> path;
    for (int v = end; v != start; v = route[v])
    {
        path.push_back(v);
    }
    path.push_back(start);
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (int v : path)
    {
        cout << v << " ";
    }
}
