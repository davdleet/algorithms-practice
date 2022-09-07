#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> temp;
vector<vector<int>> arr;
vector<vector<int>> visited;
int X, Y;
int N, M;

int BFS(int rx, int ry, int bx, int by)
{

    queue<pair<pair<int, int>, pair<int, int>>> q;
    queue<int> dis_q;
    q.push({{rx, ry}, {bx, by}});
    dis_q.push(0);
    int ans = -1;
    while (q.size())
    {
        int dis = dis_q.front();
        if (dis > 10)
        {
            // cout << "over 10\n";
            break;
        }
        pair<pair<int, int>, pair<int, int>> current = q.front();
        int x1 = current.first.first;
        int y1 = current.first.second;
        int x2 = current.second.first;
        int y2 = current.second.second;
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        q.pop();
        dis_q.pop();
        // both marbles entered the hole -- not the answer
        if (x1 == X && y1 == Y && x2 == X && y2 == Y)
        {
            // cout << "situation A"
            //      << "\n";
            continue;
        }
        // blue marble entered the hole but not the red one
        else if (x2 == X && y2 == Y)
        {
            // cout << "situation B"
            //      << "\n";
            continue;
        }
        // only the red marble entered the hole
        else if (x1 == X && y1 == Y)
        {
            // cout << "situation C"
            //      << "\n";
            // answer found
            ans = dis;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            // move the marbles
            // we need to know which marble to move first
            int a = dir[i].first;
            int b = dir[i].second;
            bool r_first = true;
            // minus direction
            // horizontal
            if (a == 0)
            {
                // move right
                if (b > 0)
                {
                    if (y2 > y1)
                    {
                        r_first = false;
                    }
                }
                // move left
                else
                {
                    if (y2 < y1)
                    {
                        r_first = false;
                    }
                }
            }
            // vertical
            else
            {
                // move down
                if (a > 0)
                {
                    if (x1 < x2)
                    {
                        r_first = false;
                    }
                }
                // move up
                else
                {
                    if (x1 > x2)
                    {
                        r_first = false;
                    }
                }
            }
            int nrx = x1;
            int nry = y1;
            int nbx = x2;
            int nby = y2;
            // move red marble first
            arr[x1][y1] = 1;
            arr[x2][y2] = 1;
            if (r_first)
            {
                while ((nrx + a) >= 1 && (nrx + a) <= N - 2 && (nry + b) >= 1 && (nry + b) <= M - 2 && (arr[nrx + a][nry + b] == 1 || arr[nrx + a][nry + b] == 4))
                {
                    nrx = nrx + a;
                    nry = nry + b;
                    if (arr[nrx][nry] == 4)
                    {
                        break;
                    }
                }

                while ((nbx + a) >= 1 && (nbx + a) <= N - 2 && (nby + b) >= 1 && (nby + b) <= M - 2 && (arr[nbx + a][nby + b] == 1 || arr[nbx + a][nby + b] == 4 || arr[nbx + a][nby + b] == 2))
                {
                    if (arr[nrx][nry] != 4 && nbx + a == nrx && nby + b == nry)
                    {
                        break;
                    }
                    nbx = nbx + a;
                    nby = nby + b;
                    if (arr[nbx][nby] == 4)
                    {
                        break;
                    }
                }
                if (!(nrx == x1 && nry == y1 && nbx == x2 && nby == y2))
                {
                    q.push({{nrx, nry}, {nbx, nby}});
                    dis_q.push(dis + 1);
                }
            }
            // move blue marble first
            else
            {
                while ((nbx + a) >= 1 && (nbx + a) <= N - 2 && (nby + b) >= 1 && (nby + b) <= M - 2 && (arr[nbx + a][nby + b] == 1 || arr[nbx + a][nby + b] == 4))
                {
                    nbx = nbx + a;
                    nby = nby + b;
                    if (arr[nbx][nby] == 4)
                    {
                        break;
                    }
                }
                while ((nrx + a) >= 1 && (nrx + a) <= N - 2 && (nry + b) >= 1 && (nry + b) <= M - 2 && (arr[nrx + a][nry + b] == 1 || arr[nrx + a][nry + b] == 4 || arr[nrx + a][nry + b] == 3))
                {
                    if (arr[nbx][nby] != 4 && nrx + a == nbx && nry + b == nby)
                    {
                        break;
                    }
                    nrx = nrx + a;
                    nry = nry + b;
                    if (arr[nrx][nry] == 4)
                    {
                        break;
                    }
                }
                if (!(nrx == x1 && nry == y1 && nbx == x2 && nby == y2))
                {
                    q.push({{nrx, nry}, {nbx, nby}});
                    dis_q.push(dis + 1);
                }
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
    cin >> N >> M;
    temp = vector<int>(M, 0);
    arr = vector<vector<int>>(N, temp);
    int rx, ry, bx, by;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            char c = s[j];
            // # == 0
            // . == 1
            // R == 2
            // B == 3
            // O == 4
            if (c == '.')
            {
                arr[i][j] = 1;
            }
            else if (c == 'R')
            {
                rx = i;
                ry = j;
                arr[i][j] = 2;
            }
            else if (c == 'B')
            {
                bx = i;
                by = j;
                arr[i][j] = 3;
            }
            else if (c == 'O')
            {
                X = i;
                Y = j;
                arr[i][j] = 4;
            }
        }
    }
    cout << BFS(rx, ry, bx, by);
}