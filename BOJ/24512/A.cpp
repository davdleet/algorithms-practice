#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int N, M;
vector<int> temp(10, 0);
vector<vector<int>> arr(10, temp);
vector<vector<int>> edge_visit(10, temp);
vector<int> visited(10, 0);
vector<int> ans;
int smallest_max = 10000000;

void bruteforce(int start, int end, vector<int> path, int max_val)
{
    // bool all_visited = true;
    // for (int i = 1; i <= N; i++)
    // {
    //     if (find(path.begin(), path.end(), i) == path.end())
    //     {
    //         all_visited = false;
    //         break;
    //     }
    // }
    // // base case
    // cout << "path " << endl;
    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout << path[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i < N + 1; i++)
    // {
    //     cout << visited[i] << " ";
    // }
    // cout << "\n\n";
    if (path.size() == N)
    {
        if (!arr[end][start])
        {
            return;
        }
        else
        {
            if (arr[end][start] > max_val)
            {
                max_val = arr[end][start];
            }
        }
        if (max_val < smallest_max)
        {
            smallest_max = max_val;
            ans = path;
        }
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            // no connection in adjacency matrix
            if (!arr[end][i])
            {
                continue;
            }
            // connection found in adjacency matrix
            else
            {
                int cost = arr[end][i];
                int new_max = max_val;
                if ((!edge_visit[end][i] && i != start && !visited[i]))
                {
                    vector<int> new_path = path;
                    new_path.push_back(i);
                    edge_visit[end][i] = true;
                    visited[i] = true;
                    if (cost > new_max)
                    {
                        new_max = cost;
                    }
                    bruteforce(start, i, new_path, new_max);
                    edge_visit[end][i] = false;
                    if (i != start)
                    {
                        visited[i] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = c;
    }
    for (int i = 1; i <= N; i++)
    {
        visited[i] = true;
        vector<int> path;
        path.push_back(i);
        bruteforce(i, i, path, -1);
        visited[i] = false;
    }
    if (!ans.size())
    {
        cout << -1;
    }
    else
    {
        cout << smallest_max << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}