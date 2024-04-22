#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> arr;
vector<vector<int>> visited;
deque<pair<int, int>> cheese_tiles;
vector<pair<int, int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
void outside(int x, int y)
{
    visited[x][y] = 1;
    arr[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int a = dir[i].first;
        int b = dir[i].second;
        if (x + a >= 0 && x + a < N && y + b >= 0 && y + b < M && (arr[x + a][y + b] == 0 || arr[x + a][y + b] == 2) && !visited[x + a][y + b])
        {
            outside(x + a, y + b);
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int n;
            cin >> n;
            arr[i][j] = n;
            if (n == 1)
                cheese_tiles.push_back(pair<int, int>(i, j));
        }
    }
    outside(0, 0);

    int cnt = 0;
    while (cheese_tiles.size())
    {
        // cout << cheese_tiles.size() << endl;
        deque<pair<int, int>> temp;
        deque<pair<int, int>> marked;
        while (cheese_tiles.size())
        {
            pair<int, int> current;
            current = cheese_tiles.front();
            cheese_tiles.pop_front();
            int x = current.first;
            int y = current.second;
            int touch = 0;
            for (int k = 0; k < dir.size(); k++)
            {
                int a = dir[k].first;
                int b = dir[k].second;
                if (x + a >= 0 && x + a < N && y + b >= 0 && y + b < M && arr[x + a][y + b] == 2)
                {
                    touch++;
                }
            }
            if (touch >= 2)
            {
                marked.push_back(current);
            }
            else
            {
                temp.push_back(current);
            }
        }
        cheese_tiles = temp;
        while (marked.size())
        {
            pair<int, int> current;
            current = marked.front();
            marked.pop_front();
            int x = current.first;
            int y = current.second;
            arr[x][y] = 2;
        }
        visited = vector<vector<int>>(N, vector<int>(M, 0));
        outside(0, 0);
        cnt++;
    }
    cout << cnt;
}