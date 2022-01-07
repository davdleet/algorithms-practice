#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int a[701][701], dy[701][701];

int main()
{
    //freopen("input.txt", "rt", stdin);
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> a[i][j];
            dy[i][j] = a[i][j] + dy[i][j - 1] + dy[i - 1][j] - dy[i - 1][j - 1];
        }
    }
    int h, w;
    cin >> h >> w;
    int max = INT_MIN;
    for (int i = h; i <= H; i++)
    {
        for (int j = w; j <= W; j++)
        {
            int area = dy[i][j] - dy[i][j - w] - dy[i - h][j] + dy[i - h][j - w];
            if (area > max)
            {
                max = area;
            }
        }
    }
    cout << max;
}