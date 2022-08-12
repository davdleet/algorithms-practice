#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> temp;
vector<vector<int>> arr;

void floyd_warshall()
{
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            // distance from j to i
            int n_dis = arr[j][i];
            // skip if i is j or n_dis is not connected
            if (i == j || !n_dis)
            {
                continue;
            }
            for (int k = 1; k < N + 1; k++)
            {
                // distance from i to k
                int k_dis = arr[i][k];
                // skip if j is k or k_dis is not connected
                if (j == k || !k_dis)
                {
                    continue;
                }
                int left = n_dis + k_dis;
                int right = arr[j][k];
                if (!left && !right)
                {
                }
                else
                {
                    if (!left)
                    {
                        left = 1e9;
                    }
                    if (!right)
                    {
                        right = 1e9;
                    }
                    arr[j][k] = min(left, right);
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    temp = vector<int>(N + 1, 0);
    arr = vector<vector<int>>(N + 1, temp);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (!arr[a][b])
        {
            arr[a][b] = c;
        }
        else
        {
            arr[a][b] = min(arr[a][b], c);
        }
    }
    floyd_warshall();
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}