#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000000];

int main()
{
    // freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v[i].first = temp;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    arr[v[0].second] = cnt;
    for (int i = 1; i < N; i++)
    {
        if (v[i].first != v[i - 1].first)
        {
            cnt++;
        }
        arr[v[i].second] = cnt;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}