#include <iostream>
#include <vector>
using namespace std;

vector<int> temp;
vector<vector<int>> arr;
vector<pair<int, int>> t1;
vector<vector<int>> dp;
vector<vector<int>> last;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<int> temp = vector<int>(n, 0);
        arr = vector<vector<int>>(2, temp);
        dp = vector<vector<int>>(3, temp);
        last = vector<vector<int>>(2, temp);
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int num;
                cin >> num;
                arr[j][k] = num;
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = 0;
        last[0][0] = 0;
        last[1][0] = 1;
        // iterate through all columns;
        for (int j = 1; j < n; j++)
        {
            // for all options
            for (int k = 0; k < 3; k++)
            {
                // pick up
                if (k == 0 || k == 1)
                {
                    // find the index of last decision
                    int last_idx = last[k][j - 1];
                    int opp = 1 - last_idx;
                    // next idx to choose
                    int choice;
                    // left is picking the opposite side of last dp
                    int left = arr[opp][j] + dp[k][j - 1];
                    // right is picking the max of current arr and the option of not picking anything for last dp
                    int right = max(arr[0][j], arr[1][j]) + dp[2][j - 1];
                    if (left >= right)
                    {
                        choice = opp;
                        dp[k][j] = left;
                    }
                    // right is bigger so dont pick from last dp[0][j-1] and dp[2][j-1]
                    else
                    {
                        if (arr[0][j] > arr[1][j])
                        {
                            choice = 0;
                        }
                        else if (arr[0][j] == arr[1][j])
                        {
                            choice = opp;
                        }
                        else
                        {
                            choice = 1;
                        }
                        dp[k][j] = right;
                    }
                    last[k][j] = choice;
                }
                // pick neither
                else
                {
                    dp[k][j] = max(dp[0][j - 1], dp[1][j - 1]);
                }
            }
        }
        cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << "\n";
    }
}