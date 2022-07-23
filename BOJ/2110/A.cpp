#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, C;
    cin >> N >> C;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int l = 1;
    int r = arr[N - 1] - arr[0];
    int ans = -1;
    while (l <= r)
    {
        // int m = (l + r) / 2;
        // int mid = arr[m] - arr[0];
        int mid = (l + r) / 2;
        int cnt = 1;
        int last = 0;
        for (int i = 1; i < N; i++)
        {
            if (arr[i] - arr[last] >= mid)
            {
                last = i;
                cnt++;
            }
        }
        // if too much routers placed, increase search dis
        if (cnt >= C)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        // if too little routers placed, decrease search dis
        else if (cnt < C)
        {
            r = mid - 1;
        }
    }
    cout << ans;
}