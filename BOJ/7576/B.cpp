#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;
vector<int> temp;
int M, N;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int BFS()
{
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num = arr[i][j];
            if (num == 1)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    int ans = 0;
    while (q.size())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;
        q.pop();
        ans = day;
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if (x + a < 0 || x + a >= N || y + b < 0 || y + b >= M || arr[x + a][y + b] != 0)
            {
                continue;
            }
            arr[x + a][y + b] = 1;
            q.push({{x + a, y + b}, day + 1});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                ans = -1;
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> M >> N;
    temp = vector<int>(M, 0);
    arr = vector<vector<int>>(N, temp);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    cout << BFS();
}