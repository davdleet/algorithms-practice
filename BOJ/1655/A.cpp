#include <iostream>
#include <set>
using namespace std;

int N;
multiset<int> ms;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        ms.insert(num);
        if (ms.size() % 2 == 0)
        {
            auto l = ms.begin();
            auto r = ms.begin();
            advance(l, ms.size() / 2 - 1);
            advance(r, ms.size() / 2 - 1);
            cout << max(*l, *r) << "\n";
        }
        else
        {
            auto m = ms.begin();
            advance(m, ms.size() / 2);
            cout << *m << "\n";
        }
    }
}