#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr;
    for (int i = 0; i < N + 1; i++)
    {
        vector<int> temp(N + 1);
        arr.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        int v, e;
        cin >> v >> e;
        arr[v][e] = 1;
        arr[e][v] = 1;
    }
    queue<int> q;
    int not_cn = N;
    int cnt = 0;
    unordered_map<int, int> d;
    for (int i = 1; i < N + 1; i++)
    {
        bool found = false;
        for (int j = 1; j < N + 1; j++)
        {
            if (arr[i][j] == 1)
            {
                found = true;
                q.push(j);
                arr[i][j] = 0;
                if (d.find(i) == d.end())
                {
                    not_cn--;
                    d[i] = 1;
                }
                if (d.find(j) == d.end())
                {
                    not_cn--;
                    d[j] = 1;
                }
            }
        }
        if (found)
        {
            cnt++;
        }
        while (q.size())
        {
            int current = q.front();
            q.pop();
            for (int j = 1; j < N + 1; j++)
            {
                if (arr[current][j] == 1)
                {
                    q.push(j);
                    arr[current][j] = 0;
                    if (d.find(i) == d.end())
                    {
                        not_cn--;
                        d[i] = 1;
                    }
                    if (d.find(j) == d.end())
                    {

                        not_cn--;
                        d[j] = 1;
                    }
                }
            }
        }
    }
    cout << cnt + not_cn;
}