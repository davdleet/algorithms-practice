#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> arr;
    arr.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<long long> dp(N + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
    }
    long long max = dp[0];
    for (int i = 1; i < N + 1; i++)
    {
        if (max == M)
        {
            break;
        }
        int r = i;
        int l = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            // subtraction is smaller
            if (dp[i] - dp[m] < M)
            {
                if (dp[i] - dp[m] > max)
                {
                    max = dp[i] - dp[m];
                }
                r = m - 1;
            }
            else if (dp[i] - dp[m] == M)
            {
                max = dp[i] - dp[m];
                break;
            }
            // subtraction is bigger
            else
            {
                l = m + 1;
            }
        }
    }
    cout << max;
}