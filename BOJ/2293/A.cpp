#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coins;
vector<int> dp;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    dp = vector<int>(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int current_coin = coins[i];
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= current_coin)
            {
                dp[j] = dp[j] + dp[j - current_coin];
            }
        }
    }
    cout << dp[k];
}