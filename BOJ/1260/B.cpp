#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;
vector<int> visited;
vector<int> temp;
int N, M, V;
void DFS(int node)
{
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < arr[node].size(); i++)
    {
        int connected = arr[node][i];
        if (!visited[connected])
        {
            DFS(connected);
        }
    }
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (q.size())
    {
        int n = q.front();
        q.pop();
        cout << n << " ";
        for (int i = 0; i < arr[n].size(); i++)
        {
            int connected = arr[n][i];
            if (!visited[connected])
            {
                visited[connected] = 1;
                q.push(connected);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> V;
    arr = vector<vector<int>>(N + 1, temp);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    visited = vector<int>(N + 1, 0);
    DFS(V);
    cout << "\n";
    visited = vector<int>(N + 1, 0);
    BFS(V);
}