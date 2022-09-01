#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input;
vector<vector<int>> arr;
vector<vector<int>> dp;
vector<int> temp;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    temp = vector<int>(N + 1, 0);
    arr = vector<vector<int>>(N + 1, temp);
    dp = vector<vector<int>>(N + 1, temp);
    int x1, y1, x2, y2;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    for (int i = 0; i < M; i++)
    {
        vector<int> temp;
        cin >> x1 >> y1 >> x2 >> y2;
        temp.push_back(x1);
        temp.push_back(y1);
        temp.push_back(x2);
        temp.push_back(y2);
        input.push_back(temp);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int up = 0;
            int left = 0;
            int overlap = 0;
            if (i - 1 >= 0)
            {
                up = dp[i - 1][j];
            }
            if (j - 1 >= 0)
            {
                left = dp[i][j - 1];
            }
            if (left && up)
            {
                overlap = dp[i - 1][j - 1];
            }
            dp[i][j] = up + left + arr[i][j] - overlap;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x1 = input[i][0];
        int y1 = input[i][1];
        int x2 = input[i][2];
        int y2 = input[i][3];
        pair<int, int> p1 = {x1, y1};
        pair<int, int> p2 = {x2, y2};
        int x_diff = p1.first - p2.first;
        int y_diff = p1.second - p2.second;
        // two points are the same
        int ans = 0;
        if (x1 == x2 && y1 == y2)
        {
            ans = arr[x1][y1];
        }
        // y1 == y2 but x2 is bigger than x1
        // same column
        else if (y1 == y2)
        {
            int left_cut = 0;
            int up_cut = 0;
            int overlapped = 0;
            if (y2 - 1 >= 0)
            {
                left_cut = dp[x2][y2 - 1];
            }
            if (x1 - 1 >= 0)
            {
                up_cut = dp[x1 - 1][y1];
            }
            if (up_cut && left_cut)
            {
                overlapped = dp[x1 - 1][y1 - 1];
            }
            ans = dp[x2][y2] - left_cut - up_cut + overlapped;
        }
        // x1 == x2 but y2 is bigger than y1
        // same row
        else if (x1 == x2)
        {
            int up_cut = 0;
            int left_cut = 0;
            int overlapped = 0;
            if (x2 - 1 >= 0)
            {
                up_cut = dp[x1 - 1][y2];
            }
            if (y1 - 1 >= 0)
            {
                left_cut = dp[x1][y1 - 1];
            }
            if (up_cut && left_cut)
            {
                overlapped = dp[x1 - 1][y1 - 1];
            }
            ans = dp[x2][y2] - up_cut - left_cut + overlapped;
        }
        // x2 and y2 bigger than x1, x2
        else
        {
            int left_cut = 0;
            int up_cut = 0;
            int overlapped = 0;
            if (y1 - 1 >= 0)
            {
                left_cut = dp[x2][y1 - 1];
            }
            if (x1 - 1 >= 0)
            {
                up_cut = dp[x1 - 1][y2];
            }
            if (left_cut && up_cut)
            {
                overlapped = dp[x1 - 1][y1 - 1];
            }
            ans = dp[x2][y2] - left_cut - up_cut + overlapped;
        }
        cout << ans << "\n";
    }
}