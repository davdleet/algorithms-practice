#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> arr;
vector<vector<int>> check;
int BFS(int xi, int yi)
{
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<vector<int>> q;
    q.push({xi, yi, 1});
    check[xi][yi] = 1;
    int ans = 0;
    while (q.size())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();
        bool break_flag = false;
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if (((x + a) < 0 || (x + a) >= N) || ((y + b) < 0 || (y + b) >= M) || (arr[x + a][y + b] == 0) || (check[x + a][y + b] == 1))
            {
                continue;
            }
            else
            {
                if ((x + a) == (N - 1) && (y + b) == (M - 1))
                {
                    ans = d + 1;
                    break_flag = true;
                    break;
                }
                q.push({x + a, y + b, d + 1});
                check[x + a][y + b] = 1;
            }
        }
        if (break_flag)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        vector<int> temp(M);
        vector<int> c(M);
        arr.push_back(temp);
        check.push_back(c);
    }
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = line[j] - '0';
        }
    }
    cout << (BFS(0, 0));
}