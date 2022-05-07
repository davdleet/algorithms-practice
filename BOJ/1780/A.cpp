#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;

vector<pair<int, int>> dir{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

vector<int> divide(int size, int x, int y)
{
    if (size == 1)
    {
        int idx = arr[x][y] + 1;

        vector<int> r(3, 0);
        r[idx] = 1;
        return r;
    }
    else
    {
        vector<vector<int>> div;
        int s = int(size / 3);
        vector<int> ans(3, 0);
        for (int i = 0; i < dir.size(); i++)
        {
            vector<int> temp = divide(s, x + dir[i].first * s, y + dir[i].second * s);
            div.push_back(temp);
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans[j] += div[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (ans[i] == (size * size) / (s * s))
            {
                ans[i] = 1;
            }
        }
        return ans;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            temp.push_back(n);
        }
        arr.push_back(temp);
    }
    vector<int> result = divide(N, 0, 0);
    cout << result[0] << "\n"
         << result[1] << "\n"
         << result[2];
}