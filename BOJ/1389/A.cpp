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
    for (int i = 0; i < N + 1; i++)
    {
        vector<int> temp(N + 1, 1000000);
        arr.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     for (int j = 1; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    bool action = true;
    while (action)
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
                for (int k = 1; k < N + 1; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    if (arr[i][j] + arr[j][k] < arr[i][k])
                    {
                        action = true;
                        arr[i][k] = arr[i][j] + arr[j][k];
                    }
                }
            }
        }
    }

    int min_idx = 0;
    int min_num = 100000000;
    for (int i = 1; i < N + 1; i++)
    {
        int temp = 0;
        for (int j = 1; j < N + 1; j++)
        {
            temp += arr[i][j];
        }
        if (temp < min_num)
        {
            min_num = temp;
            min_idx = i;
        }
    }
    // cout << endl;
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     for (int j = 1; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << min_idx;
}