#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> dp(N, 0);
    vector<int> r_dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr[i] = n;
    }
    // left to right dp
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] < arr[i] && r_dp[i] < r_dp[j] + 1)
            {
                // dp[i] = dp[j] + 1;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // right to left reverse dp
    for (int i = N - 1; i >= 0; i--)
    {
        r_dp[i] = 1;
        for (int j = N - 1; j >= i; j--)
        {
            if (arr[j] < arr[i] && r_dp[i] < r_dp[j] + 1)
            {
                r_dp[i] = r_dp[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] + r_dp[i] > ans)
        {
            ans = dp[i] + r_dp[i] - 1;
        }
    }
    cout << ans;
}