#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<int> visited;
vector<int> temp;

int DFS(int node)
{
    int ans = 0;
    if (node != 1)
    {
        ans = 1;
    }
    visited[node] = 1;
    for (int i = 0; i < arr[node].size(); i++)
    {
        if (!visited[arr[node][i]])
        {
            ans += DFS(arr[node][i]);
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1, temp);
    visited = vector<int>(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int node, connected;
        cin >> node >> connected;
        arr[node].push_back(connected);
        arr[connected].push_back(node);
    }
    int ans = DFS(1);
    cout << ans;
}