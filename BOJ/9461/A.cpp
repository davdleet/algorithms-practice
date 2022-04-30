#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> arr;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<long long> arr(N + 1, 0);
        if (N <= 3)
        {
            cout << 1 << "\n";
            continue;
        }
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        for (int j = 4; j < N + 1; j++)
        {
            arr[j] = arr[j - 3] + arr[j - 2];
        }
        cout << arr[N] << "\n";
    }
}