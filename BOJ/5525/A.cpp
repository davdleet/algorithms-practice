#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int L;
    cin >> L;
    string S;
    cin >> S;
    string to_find = "I";
    for (int i = 0; i < N; i++)
    {
        to_find += "OI";
    }
    int f_len = to_find.size();
    string s = S;
    int cnt = 0;
    int start = 0;
    // initial starting point
    int idx = s.find(to_find);
    while (idx != -1)
    {
        cnt++;
        int i = idx + f_len;
        // check for more
        while (i < s.size() - 1 && string(1, s[i]) + string(1, s[i + 1]) == "OI")
        {
            i += 2;
            cnt++;
        }
        // if i is out of bounds, break
        if (i >= L - 1)
        {
            break;
        }
        idx = s.find(to_find, i);
    }
    cout << cnt;
}