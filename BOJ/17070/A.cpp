#include <iostream>
#include <vector>
using namespace std;

bool valid(int N, int x, int y)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    // 0: -, 1: |, 2: \.
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    dp[0][1][2] = 1;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // 0 : 0, 2
                if (k == 0 && dp[k][i][j])
                {
                    if (valid(N, i, j + 1) && !arr[i][j + 1])
                    {
                        dp[0][i][j + 1] += dp[k][i][j];
                    }
                    if (valid(N, i + 1, j + 1) && !arr[i][j + 1] && !arr[i + 1][j + 1] && !arr[i + 1][j])
                    {
                        dp[2][i + 1][j + 1] += dp[k][i][j];
                    }
                }
                // 1 : 1, 2
                else if (k == 1)
                {
                    if (valid(N, i + 1, j) && !arr[i + 1][j])
                    {
                        dp[1][i + 1][j] += dp[k][i][j];
                    }
                    if (valid(N, i + 1, j + 1) && !arr[i][j + 1] && !arr[i + 1][j + 1] && !arr[i + 1][j])
                    {
                        dp[2][i + 1][j + 1] += dp[k][i][j];
                    }
                }
                // 2 : 0, 1, 2
                else
                {
                    if (valid(N, i, j + 1) && !arr[i][j + 1])
                    {
                        dp[0][i][j + 1] += dp[k][i][j];
                    }
                    if (valid(N, i + 1, j) && !arr[i + 1][j])
                    {
                        dp[1][i + 1][j] += dp[k][i][j];
                    }
                    if (valid(N, i + 1, j + 1) && !arr[i][j + 1] && !arr[i + 1][j + 1] && !arr[i + 1][j])
                    {
                        dp[2][i + 1][j + 1] += dp[k][i][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += dp[i][N][N];
    }
    cout << ans;
}
