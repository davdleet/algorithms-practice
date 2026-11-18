#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<vector<int>> adj_list(N + 1, vector<int>());
    vector<int> visited(N + 1, 0);
    vector<int> shortest(N + 1, 1000000000);
    for (int i = 0; i < M; i++)
    {
        int start, dest;
        cin >> start >> dest;
        adj_list[start].push_back(dest);
    }
    queue<pair<int, int>> q;
    visited[X] = 1;
    q.push({X, 0});
    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop();
        int town = p.first;
        int dis = p.second;
        shortest[town] = dis;
        if (dis > K)
        {
            break;
        }
        for (int i = 0; i < adj_list[town].size(); i++)
        {
            int dest = adj_list[town][i];
            if (!visited[dest])
            {
                q.push({dest, dis + 1});
                visited[dest] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < shortest.size(); i++)
    {
        if (shortest[i] == K)
        {
            cnt++;
            cout << i << endl;
        }
    }
    if (cnt == 0)
    {
        cout << -1;
    }
}