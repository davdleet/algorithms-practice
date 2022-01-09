#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct d
{
    int pos = 0;
    int range = 0;
    int idx = 0;
    d(int a, int b, int c)
    {
        pos = a;
        range = b;
        idx = c;
    }
    d()
    {
    }
};

bool f(d a, d b)
{
    if (a.range == b.range)
    {
        return a.pos > b.pos;
    }
    else
    {
        return a.range > b.range;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<d> v(N);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v[i].pos = temp;
        v[i].idx = i;
    }
    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        cin >> temp;
        v[i].range = temp;
    }
    sort(v.begin(), v.end(), f);
    for (int i = 0; i < v.size(); i++)
    {
        int tempidx = v[i].idx;
        arr[tempidx] = i;
    }
    int idx = 0;

    while (idx < (N - 1))
    {
        d current = v[arr[idx]];
        int start = idx;
        for (int i = 0; i < N; i++)
        {
            if ((current.pos + current.range) >= v[i].pos && current.idx < v[i].idx)
            {
                idx = v[i].idx;
                break;
            }
        }
        if (idx == start)
        {
            cout << "엄마 나 전역 늦어질 것 같아";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다";
}