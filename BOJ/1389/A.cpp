#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr;
    vector<int> sums(N + 1, 0);
    for (int i = 0; i < N + 1; i++)
    {
        vector<int> temp(N + 1, 0);
        arr.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
        sums[a] += 1;
        sums[b] += 1;
    }
    bool action = false;
    int loop_cnt = 0;
    while (!action)
    {
        action = false;
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < N + 1; j++)
            {
                if (j == i)
                {
                    continue;
                }
                else
                {
                    if (arr[i][j])
                    {
                        for (int k = 1; k < N + 1; k++)
                        {
                            if (k == i)
                            {
                                continue;
                            }
                            else
                            {
                                if (arr[j][k])
                                {
                                    action = true;
                                    if (arr[i][k])
                                    {
                                        sums[i] -= arr[i][k];
                                        int temp = min(arr[i][k], arr[j][k] + 1);
                                        arr[i][k] = temp;
                                        sums[i] += temp;
                                    }
                                    else
                                    {
                                        arr[i][k] = arr[j][k] + 1;
                                        sums[i] += arr[j][k] + 1;
                                    }
                                }
                                int temp2 = min(arr[k][i], arr[j][k] + 1);
                                if (arr[k][i])
                                {
                                    action = true;
                                    sums[i] -= arr[k][i];

                                    arr[k][i] = temp2;
                                    sums[i] += temp2;
                                }
                                else
                                {
                                    action = true;
                                    arr[k][i] = temp2;
                                    sums[i] += temp2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int num = 90000000;
    int smallest_idx = -1;
    for (int i = 1; i < N + 1; i++)
    {
        cout << sums[i] << "\n";
        if (sums[i] < num)
        {
            num = sums[i];
            smallest_idx = i;
        }
    }
    // for (int i = 1; i < N + 1; i++)
    // {
    //     cout << sums[i] << " ";
    // }

    // cout << endl;
    // for (int i = 1; i < N + 1; i++)
    // {
    //     for (int j = 1; j < N + 1; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << smallest_idx;
}