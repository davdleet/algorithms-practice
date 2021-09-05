#include <iostream>

using namespace std;

int main()
{
    int N;
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &N);
    int lt, current, rt, K;
    lt = 1;
    K = 1;
    int res = 0;
    while (lt != 0)
    {
        lt = N / (K * 10);
        current = (N / K) % 10;
        rt = N % K;
        if (current > 3)
        {
            res = res + ((lt + 1) * K);
        }
        else if (current < 3)
        {
            res = res + (lt * K);
        }
        else
        {
            res = res + (lt * K + (rt + 1));
        }
        K = K * 10;
    }
    cout << res << endl;
}
