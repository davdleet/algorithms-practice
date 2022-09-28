#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (b % a == 0 && b != a)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}