#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    char start;
    cin >> start;
    string pass = "ILOVEYONSEI";
    char current = start;
    int ans = 0;
    for (int i = 0; i < pass.size(); i++)
    {
        int diff = abs(pass[i] - current);
        ans += diff;
        current = pass[i];
    }
    cout << ans;
}