#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

vector<vector<int>> arr;
vector<int> temp;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> visited;
int N, M;
bool check_boundaries(int x, int y)
{
    if (x < N && x >= 0 && y < M && y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, E, K;
    cin >> N >> M;
    cin >> L >> E >> K;
    temp = vector<int>(M, 0);
    arr = vector<vector<int>>(N, temp);
    visited = vector<vector<int>>(N, temp);
    map<int, int> monsters;
    int s_x, s_y;
    int r_x, r_y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            if (num == -3)
            {
                s_x = i;
                s_y = j;
            }
            else if (num == -2)
            {
                r_x = i;
                r_y = j;
            }
            arr[i][j] = num;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    deque<vector<int>> q;
    q.push_back({s_x, s_y, L, E});
    visited[s_x][s_y] = 1;
    bool success = false;
    while (q.size())
    {
        vector<int> current = q.front();
        q.pop_front();
        int x, y, l, e;
        x = current[0];
        y = current[1];
        l = current[2];
        e = current[3];
        if (x == r_x && y == r_y)
        {
            cout << "reached" << endl;
            if (l == L && e == E)
            {
                success = true;
                break;
            }
        }
        int r = l - e;
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if (check_boundaries(x + a, y + b) && arr[x + a][y + b] != -1)
            {
                // monster
                if (arr[x + a][y + b] > 0)
                {
                    // lower lvl than player, never met
                    if (arr[x + a][y + b] < l && monsters.find(arr[x + a][y + b]) == monsters.end())
                    {
                        e = e + arr[x + a][y + b];
                        if (e >= l)
                        {
                            e = e - l;
                            l++;
                        }
                        q.push_back({x + a,
                                     y + b,
                                     l, e});
                        monsters.insert({arr[x + a][y + b], 1});
                        visited[x + a][y + b] = 1;
                    }
                    else if (arr[x + a][y + b] < l && monsters.find(arr[x + a][y + b]) != monsters.end())
                    {
                        q.push_back({x + a,
                                     y + b,
                                     l, e});
                        visited[x + a][y + b] = 1;
                    }
                }
                else
                {
                    q.push_back({x + a, y + b, l, e});
                    visited[x + a][y + b] = 1;
                }
            }
        }
    }
    if (success)
    {
        cout << "O";
    }
    else
    {
        cout << "X";
    }
}