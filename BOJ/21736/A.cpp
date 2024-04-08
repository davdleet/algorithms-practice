#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<char>> campus(N, vector<char>(M, 'O'));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int cnt = 0;
    int start_x;
    int start_y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            campus[i][j] = ch;
            if (ch == 'I')
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    vector<pair<int, int>> dir{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    deque<pair<int, int>> q;
    q.push_back(pair<int, int>(start_x, start_y));
    visited[start_x][start_y] = 1;
    while (q.size())
    {
        pair<int, int> current;
        current = q.front();
        q.pop_front();
        int x = current.first;
        int y = current.second;
        char c;
        c = campus[x][y];
        if (c == 'P')
        {
            cnt++;
        }
        for (int i = 0; i < dir.size(); i++)
        {
            int a, b;
            a = dir[i].first;
            b = dir[i].second;
            if (x + a >= 0 && x + a < N && y + b >= 0 && y + b < M && !visited[x + a][y + b] && (campus[x + a][y + b] != 'X'))
            {
                visited[x + a][y + b] = 1;
                q.push_back(pair<int, int>(x + a, y + b));
            }
        }
    }
    if (cnt == 0)
    {
        cout << "TT";
        return 0;
    }
    cout << cnt;
}