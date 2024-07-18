#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    deque<int> arr;
    vector<int> fruits(10, 0);
    int types = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int f;
        cin >> f;
        if (fruits[f]++ == 0)
        {
            types++;
        }
        arr.push_back(f);
        while (types >= 3)
        {
            int r = arr.front();
            arr.pop_front();
            if (--fruits[r] == 0)
            {
                types--;
            }
        }
        ans = max(ans, int(arr.size()));
    }
    cout << ans;
}