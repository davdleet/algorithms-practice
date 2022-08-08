#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> visited(1001, 0);
vector<int> temp(1001, 0);
vector<vector<int>> arr(1001, temp);

void DFS(int current)
{
    cout << current << " ";
    for (int i = 1; i < 1001; i++)
    {
        if (!arr[current][i] || visited[i])
        {
            continue;
        }
        visited[i] = 1;
        DFS(i);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    visited[V] = 1;
    DFS(V);
    cout << "\n";
    deque<int> q;
    visited = vector<int>(1001, 0);
    visited[V] = 1;
    q.push_back(V);
    while (q.size())
    {
        int current = q.front();
        cout << current << " ";
        q.pop_front();
        for (int i = 1; i < 1001; i++)
        {
            if (!arr[current][i] || visited[i])
            {
                continue;
            }
            visited[i] = 1;
            q.push_back(i);
        }
    }
}