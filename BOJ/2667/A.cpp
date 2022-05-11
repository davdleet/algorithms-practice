#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> check;
vector<vector<int>> arr;
vector<int> ans;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N;
int BFS(int xi, int yi)
{
    queue<pair<int, int>> q;
    q.push({xi, yi});
    int cnt = 0;
    check[xi][yi] = 1;
    while (q.size())
    {
        int x;
        int y;
        pair<int, int> current = q.front();
        x = current.first;
        y = current.second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            int v1 = x + a;
            int v2 = y + b;
            if ((v1 < 0 || v1 >= N) || (v2 < 0 || v2 >= N) || (check[v1][v2] == 1) || (arr[v1][v2] != 1))
            {
                continue;
            }
            q.push({v1, v2});
            check[v1][v2] = 1;
        }
    }
    return cnt;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        vector<int> check_temp(N, 0);
        string t;
        cin >> t;
        for (int j = 0; j < N; j++)
        {
            temp.push_back(int(t[j]) - '0');
        }
        arr.push_back(temp);
        check.push_back(check_temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] && !check[i][j])
            {
                int temp = BFS(i, j);
                ans.push_back(temp);
            }
        }
    }
    int cnt = ans.size();
    sort(ans.begin(), ans.end());
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << "\n";
    }
}