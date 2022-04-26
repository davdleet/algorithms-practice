#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int dp[50001];
    dp[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[1] + dp[i - 1];
        for (int j = 2; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N];
}