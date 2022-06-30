#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    vector<vector<int>> arr;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
    vector<int> v(3, 0);
    vector<vector<int>> dp(N, v);
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vector<int> temp;
            for (int k = 0; k < 3; k++)
            {
                if (k == j)
                {
                    continue;
                }
                temp.push_back(dp[i - 1][k]);
            }
            dp[i][j] = arr[i][j] + *min_element(temp.begin(), temp.end());
        }
    }
    cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());
}