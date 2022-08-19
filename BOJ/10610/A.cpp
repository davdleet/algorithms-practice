#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> arr;

bool mysort(char a, char b)
{
    return a - '0' > b - '0';
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end(), mysort);
    if (s[s.size() - 1] != '0')
    {
        cout << -1;
        return 0;
    }
    long long num = 0;
    for (long long i = 0; i < s.size(); i++)
    {
        num += (s[i] - '0');
    }
    if (!(num % 3))
    {
        cout << s;
    }
    else
    {
        cout << -1;
    }
}