#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool my_sort(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        if (a.first < b.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    int ans = 0;
    int last_idx = -1;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({s, e});
    }
    sort(arr.begin(), arr.end(), my_sort);
    for (int i = 0; i < N; i++)
    {
        if (arr[i].first >= last_idx)
        {
            ans++;
            last_idx = arr[i].second;
        }
    }
    cout << ans;
}