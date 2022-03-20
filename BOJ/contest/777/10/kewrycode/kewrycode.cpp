#include <vector>
using namespace std;

vector<long long> calc(const vector<long long>& v , int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    for (int x = 1; x < N; x++) {
        for (int y = 0; y < x; y++) {
            long long m = 1000000000000000000; // (1e18)
            for (int z = y; z <= x; z++) {
                m = min(m, v[z]);
            }

            ans[x] = ans[x] + ans[y] * m;
            ans[x] = ans[x] % 1000000007; // (1e9 + 7)
        }
    }

    return ans;
}

