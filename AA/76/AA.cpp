#include <iostream>

using namespace std;
int arr[21][21];

int DFS(int n, int r)
{
    if (arr[n][r] > 0)
    {
        return arr[n][r];
    }
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return arr[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N, R;
    cin >> N >> R;
    cout << DFS(N, R);
}