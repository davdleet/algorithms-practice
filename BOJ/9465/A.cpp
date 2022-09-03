#include <iostream>
#include <vector>
using namespace std;

vector<int> temp;
vector<vector<int>> arr;
vector<pair<int, int>> t1;
vector<vector<int>> dp;
vector<vector<int>> last;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<int> temp = vector<int>(n, 0);
        arr = vector<vector<int>>(2, temp);
        dp = vector<vector<int>>(3, temp);
        last = vector<vector<int>>(2, temp);
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int num;
                cin >> num;
                arr[j][k] = num;
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = 0;
        last[0][0] = 0;
        last[1][0] = 1;
        // iterate through all columns;
        for (int j = 1; j < n; j++)
        {
            // for all options
            for (int k = 0; k < 2; k++)
            {
                if (j >= 2)
                {
                    dp[k][j] = max(dp[1 - k][j - 1], max(dp[0][j - 2], dp[1][j - 2])) + arr[k][j];
                }
                else
                {
                    dp[k][j] = dp[1 - k][j - 1] + arr[k][j];
                }
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
}