#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    long long int N, K;
    cin >> N >> K;
    long long int l, r;
    l = 1;
    r = N * N;
    long long int ans = 0;
    while (l <= r)
    {
        long long int cnt = 0;
        long long int m = (l + r) / 2;
        for (long long int i = 1; i <= N; i++)
        {
            long long int smaller_cnt = min(N, m / i);
            cnt += smaller_cnt;
        }
        if (cnt >= K)
        {
            ans = m;
            r = m - 1;
        }
        else if (cnt > K)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;
}
