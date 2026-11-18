#include <iostream>

using namespace std;

int main()
{
    freopen("A.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int cnt = 0;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                for (int k = 1; k <= c; k++)
                {
                    if ((i % j) == (j % k) && (i % j) == (k % i))
                    {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}