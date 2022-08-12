#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp(25, 0);
vector<vector<int>> arr(25, temp);
vector<vector<int>> visited(25, temp);
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> ans;
int cnt = 0;
void DFS(int x, int y)
{
    cnt++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int a = dir[i].first;
        int b = dir[i].second;
        if (x + a >= 0 && x + a < 25 && y + b >= 0 && y + b < 25 && !visited[x + a][y + b] && arr[x + a][y + b])
        {
            DFS(x + a, y + b);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
        {
            int num = line[j] - '0';
            arr[i][j] = num;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                DFS(i, j);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}