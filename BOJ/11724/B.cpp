#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> arr;
vector<int> visited(1001, 0);

void DFS(int current)
{
    visited[current] = 1;
    for (int i = 0; i < arr[current].size(); i++)
    {
        int next = arr[current][i];
        if (visited[next])
        {
            continue;
        }
        DFS(next);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && arr[i].size())
        {
            DFS(i);
            ans++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ans++;
        }
    }
    cout << ans;
}