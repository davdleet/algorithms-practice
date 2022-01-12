#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int current = int(s[i]) - '0';
        sum += current;
    }
    cout << sum;
}