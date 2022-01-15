#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            sum += i;
        }
    }
    cout << sum;
}