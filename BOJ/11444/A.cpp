#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000007;

vector<pair<long long, long long>> arr;

// multiplies 2*2 matrices
vector<pair<long long, long long>> mult(vector<pair<long long, long long>> a1, vector<pair<long long, long long>> a2)
{
    vector<pair<long long, long long>> result = vector<pair<long long, long long>>(2, {0, 0});
    result[0].first = (a1[0].first * a2[0].first + a1[0].second * a2[1].first) % MOD;
    result[0].second = (a1[0].first * a2[0].second + a1[0].second * a2[1].second) % MOD;
    result[1].first = (a1[1].first * a2[0].first + a1[1].second * a2[1].first) % MOD;
    result[1].second = (a1[1].first * a2[0].second + a1[1].second * a2[1].second) % MOD;
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        cout << 1;
        return 0;
    }
    vector<pair<long long, long long>> o = vector<pair<long long, long long>>(2, {1, 1});
    o[1].second = 0;
    vector<pair<long long, long long>> m = vector<pair<long long, long long>>(2, {0, 0});
    m[0].first = 1;
    m[1].second = 1;
    long long times = n;
    while (times > 0)
    {
        if (times % 2 == 1)
        {
            m = mult(m, o);
        }
        o = mult(o, o);
        times /= 2;
    }
    cout << m[1].first;
}