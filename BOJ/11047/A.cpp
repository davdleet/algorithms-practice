#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    struct
    {
        bool operator()(int a, int b) const { return a > b; }
    } customGreater;
    sort(arr.begin(), arr.end(), customGreater);
    int left = K;
    int coins = 0;
    int idx = 0;
    while (left > 0)
    {
        if (arr[idx] > left)
        {
            idx++;
            continue;
        }
        else
        {
            left = left - arr[idx];
            coins++;
        }
    }
    cout << coins;
}