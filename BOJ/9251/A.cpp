#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> temp;
vector<vector<int>> dp;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    temp = vector<int>(s1.size() + 1, 0);
    dp = vector<vector<int>>(s2.size() + 1, temp);
    for (int i = 1; i <= s2.size(); i++)
    {
        char a = s2[i - 1];
        for (int j = 1; j <= s1.size(); j++)
        {
            char b = s1[j - 1];
            if (a == b)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[s2.size()][s1.size()];
}