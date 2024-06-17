#include <iostream>
#include <vector>
using namespace std;

int X = 1000000007;

// Function to compute (a^b) % mod
int mod_exp(int a, int b, int mod)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (1LL * result * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b /= 2;
    }
    return result;
}

int findinv(int a, int mod)
{
    // Fermat's Little Theorem: a^(mod-2) % mod = a^-1 % mod
    return mod_exp(a, mod - 2, mod);
}

int formulate(int N, int S)
{
    // formula a × b^-1 mod X
    // = S x N ^ -1 mod x
    int N_inv = findinv(N, X);
    return ((1LL * S * N_inv) % X);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int N, S;
    vector<int> arr;
    vector<int> Ns;
    vector<int> Ss;
    while (cin >> N)
    {
        cin >> S;
        Ns.push_back(N);
        Ss.push_back(S);
    }
    int ans = 0;
    for (int i = 0; i < Ns.size(); i++)
    {
        ans = (ans + formulate(Ns[i], Ss[i]));
        ans %= X;
    }
    cout << ans;
}