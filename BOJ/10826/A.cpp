#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr(10001, 0);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[N];
}