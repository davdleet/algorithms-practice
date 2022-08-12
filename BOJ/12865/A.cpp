#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
int N, K;
int sum = 0;
int cost = 0;
vector<pair<int, int>> arr(101, {0, 0});
vector<int> temp(100001, 0);
vector<vector<int>> dp(101, temp);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int w, v;
        cin >> w >> v;
        arr[i].first = w;
        arr[i].second = v;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            int I, J;
            J = j - arr[i].first;
            if (J >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][J] + arr[i].second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}