#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int N, M;
        cin >> N >> M;
        // if (N == M)
        // {
        //     cout << 1 << endl;
        //     continue;
        // }
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        // base case
        for (int i = 0; i < M + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < M + 1; i++)
        {
            for (int j = 1; j < min(i, N) + 1; j++)
            {
                if (j == 0 || i == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }
        cout << dp[M][N] << endl;
    }
}