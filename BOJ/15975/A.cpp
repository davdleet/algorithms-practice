#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<long long> t;
    vector<vector<long long>> arr(N + 1, t);
    for (int i = 0; i < N; i++)
    {
        long long pos, col;
        cin >> pos >> col;
        arr[col].push_back(pos);
    }
    long long ans = 0;
    for (int i = 1; i < N + 1; i++)
    {
        int size = arr[i].size();
        if (size)
        {
            if (size == 1)
            {
                continue;
            }
            sort(arr[i].begin(), arr[i].end());
            for (int j = 0; j < size; j++)
            {
                int front, back;
                // first element;
                if (j == 0)
                {
                    ans += (arr[i][j + 1] - arr[i][j]);
                }
                // last element
                else if (j == size - 1)
                {
                    ans += (arr[i][j] - arr[i][j - 1]);
                }
                // in between
                else
                {
                    long long add = min((arr[i][j] - arr[i][j - 1]), (arr[i][j + 1] - arr[i][j]));
                    ans += add;
                }
            }
        }
        else
        {
            continue;
        }
    }
    cout << ans;
}