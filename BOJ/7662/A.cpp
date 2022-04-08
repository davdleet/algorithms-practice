#include <iostream>
#include <set>
#include <cstdint>
#include <unordered_map>
using namespace std;

class dQueue
{
public:
    dQueue()
    {
    }

    void I(int32_t n)
    {
        auto f = d.find(n);
        if (f == d.end())
        {
            d.insert({n, 1});
            q.insert(n);
        }
        else
        {
            f->second = f->second + 1;
        }
    }

    void D(int32_t n)
    {
        if (q.size() == 0)
        {
            return;
        }
        else
        {
            // remove smallest
            if (n == -1)
            {
                auto f = d.find(*q.begin());
                if (f != d.end())
                {
                    f->second--;
                    if (f->second == 0)
                    {
                        d.erase(f);
                        q.erase(q.begin());
                    }
                }
            }
            // remove largest
            else
            {
                auto f = d.find(*q.rbegin());
                if (f != d.end())
                {
                    f->second--;
                    if (f->second == 0)
                    {
                        d.erase(f);
                        q.erase(--q.end());
                    }
                }
            }
        }
    }

    void print()
    {
        if (q.size() == 0)
        {
            cout << "EMPTY"
                 << "\n";
            return;
        }
        cout << *q.rbegin() << " " << *q.begin() << "\n";
    }
    set<int32_t> q;
    unordered_map<int, int> d;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int K;
        cin >> K;
        dQueue q = dQueue();
        for (int j = 0; j < K; j++)
        {
            char C;
            int32_t n;
            cin >> C >> n;
            if (C == 'D')
            {
                q.D(n);
            }
            else
            {
                q.I(n);
            }
        }
        q.print();
    }
}