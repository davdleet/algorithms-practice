#include <iostream>
#include <vector>
using namespace std;

vector<int> temp;
vector<vector<int>> arr;
int N, M, W;
bool floyd_warshall()
{
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            // distance from j to i
            int i_dis = arr[j][i];
            // if i is j, skip
            if (!i_dis)
            {
                continue;
            }
            for (int k = 1; k < N + 1; k++)
            {
                // distance from i to k
                int k_dis = arr[i][k];
                if (!k_dis)
                {
                    continue;
                }
                int left = i_dis + k_dis;
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
                    if (k == j && arr[j][k] < 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {

        cin >> N >> M >> W;
        temp = vector<int>(N + 1, 0);
        arr = vector<vector<int>>(N + 1, temp);
        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            // both uninitialized
            if (!arr[S][E] && !arr[E][S])
            {
                arr[S][E] = T;
                arr[E][S] = T;
            }
            else if (!arr[S][E])
            {
                arr[S][E] = T;
                arr[E][S] = min(arr[E][S], T);
            }
            else if (!arr[E][S])
            {
                arr[E][S] = T;
                arr[S][E] = min(arr[S][E], T);
            }
            // both initialized
            else
            {
                arr[S][E] = min(arr[S][E], T);
                arr[E][S] = min(arr[E][S], T);
            }
        }
        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            if (!arr[S][E])
            {
                arr[S][E] = -T;
            }
            else
            {
                arr[S][E] = min(arr[S][E], -T);
            }
        }
        if (floyd_warshall())
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
        // for (int i = 1; i < N + 1; i++)
        // {
        //     for (int j = 1; j < N + 1; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
}