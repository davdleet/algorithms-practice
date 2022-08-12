#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(1001, 0);

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        // odd
        if (i % 2)
        {
            dp[i] = (dp[i - 1] * 2 - 1) % 10007;
        }
        // even
        else
        {
            dp[i] = (dp[i - 1] * 2 + 1) % 10007;
        }
    }
    cout << dp[n];
}