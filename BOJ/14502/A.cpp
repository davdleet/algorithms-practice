#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> arr)
{
    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    queue<pair<int, int>> q;
    int N = arr.size();
    int M = arr[0].size();
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        arr[x][y] = 2;
        for (int i = 0; i < 4; i++)
        {

            int a = dir[i].first;
            int b = dir[i].second;
            if (x + a < N && x + a >= 0 && y + b < M && y + b >= 0 && !visited[x + a][y + b] && arr[x + a][y + b] == 0)
            {
                visited[x + a][y + b] = 1;
                q.push({x + a, y + b});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    vector<pair<int, int>> coord;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            int temp;
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                coord.push_back({i, j});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < coord.size(); i++)
    {
        int x1 = coord[i].first;
        int y1 = coord[i].second;
        arr[x1][y1] = 1;
        for (int j = 0; j < coord.size(); j++)
        {
            int x2 = coord[j].first;
            int y2 = coord[j].second;
            if (j == i)
            {
                continue;
            }
            arr[x2][y2] = 1;
            for (int k = 0; k < coord.size(); k++)
            {
                int x3 = coord[k].first;
                int y3 = coord[k].second;
                if (k == i || k == j)
                {
                    continue;
                }
                arr[x3][y3] = 1;
                ans = max(ans, BFS(arr));
                arr[x3][y3] = 0;
            }
            arr[x2][y2] = 0;
        }
        arr[x1][y1] = 0;
    }
    cout << ans;
}