#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int arr[50001];
    for (int i = 0; i < 50001; i++)
    {
        arr[i] = i * i;
    }
    int copy = N;
    int cnt = 0;
    int idx = 50000;
    while (copy != 0)
    {
        if (arr[idx] > copy)
        {
            idx--;
            continue;
        }
        else
        {
            copy = copy - arr[idx];
            cnt++;
        }
    }
    cout << cnt;
}