#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int ans = 0;
pair<int, int> divide(int size, int x, int y)
{
    if (size == 1)
    {
        return {arr[x][y], 1 - arr[x][y]};
    }
    else
    {
        pair<int, int> a, b, c, d;
        a = divide(size / 2, x, y);
        b = divide(size / 2, x, y + size / 2);
        c = divide(size / 2, x + size / 2, y);
        d = divide(size / 2, x + size / 2, y + size / 2);
        int leftover = a.second + b.second + c.second + d.second;
        if (a.first + b.first + c.first + d.first == 4 && leftover == 0)
        {
            return {1, 0};
        }
        if (a.first + b.first + c.first + d.first == 0)
        {
            leftover = 1;
        }
        pair<int, int> ans = {a.first + b.first + c.first + d.first, leftover};
        return ans;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> temp;
    arr.push_back(temp);
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        temp.push_back(0);
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
    pair<int, int> ans = divide(N, 1, 1);
    cout << ans.second << "\n"
         << ans.first;
}