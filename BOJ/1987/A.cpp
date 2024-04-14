#include <iostream>
#include <deque>
#include <map>
#include <vector>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited;
map<char, int> m;

vector<vector<int>> dir{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int DFS(int x, int y, int cnt)
{
    int ans = cnt;
    visited[x][y] = 1;
    m[arr[x][y]] = 1;
    for (int i = 0; i < dir.size(); i++)
    {
        int result = -1;
        int a = dir[i][0];
        int b = dir[i][1];

        if (x + a >= 0 && x + a < arr.size() && y + b >= 0 && y + b < arr[0].size() && !visited[x + a][y + b])
        {
            auto it = m.find(arr[x + a][y + b]);
            if (it == m.end() || it->second == 0)
            {
                result = DFS(x + a, y + b, cnt + 1);
            }
        }
        ans = max(ans, result);
    }
    m[arr[x][y]] = 0;
    visited[x][y] = 0;
    return ans;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int R, C;
    cin >> R >> C;
    arr = vector<vector<char>>(R, vector<char>(C, ' '));
    visited = vector<vector<int>>(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char n;
            cin >> n;
            arr[i][j] = n;
        }
    }

    int ans = DFS(0, 0, 1);
    cout << ans;
}