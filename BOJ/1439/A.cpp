#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    iostream::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    string s;
    cin >> s;
    char c = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != c)
        {
            c = s[i];
            cnt++;
        }
    }
    if (cnt != 0)
        cout << (cnt + 1) / 2;
    else
        cout << 0;
}