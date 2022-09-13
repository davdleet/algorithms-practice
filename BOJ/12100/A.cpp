#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

vector<int> temp;
vector<vector<int>> arr;

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// vector<pair<int, int>> dir = {{1, 0}};
int find_biggest()
{
    queue<pair<int, vector<vector<int>>>> q;
    vector<vector<int>> first = arr;
    int biggest = 0;
    q.push({0, first});
    while (q.size())
    {
        int cnt = q.front().first;
        if (cnt >= 6)
        {
            break;
        }
        vector<vector<int>> map = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            // move horizontally
            if (a == 0)
            {
                // move left
                if (b == -1)
                {
                    // start with the leftmost block
                    for (int j = 0; j < N; j++)
                    {
                        for (int k = 0; k < N; k++)
                        {
                            // a block exists in the coordinate
                            if (map[j][k])
                            {
                                int o_val = map[j][k];
                                map[j][k] = 0;
                                // find where to stop
                                int k_idx = k - 1;
                                int last_idx = k;
                                bool merge = false;
                                while (true)
                                {
                                    if (k_idx < 0)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        int val = map[j][k_idx];
                                        // check for value in new coordinates
                                        // occupied
                                        if (val)
                                        {
                                            // same values
                                            // we can move to j_idx by merging
                                            if (val == o_val)
                                            {
                                                merge = true;
                                                last_idx = k_idx;
                                                break;
                                            }
                                            // different values
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        // we can move to j_idx because its empty
                                        else
                                        {
                                            last_idx = k_idx;
                                        }
                                    }
                                    k_idx--;
                                }
                                if (merge)
                                {
                                    map[j][last_idx] = map[j][last_idx] * 2;
                                }
                                else
                                {
                                    map[j][last_idx] = o_val;
                                }
                                if (map[j][last_idx] > biggest)
                                {
                                    biggest = map[j][last_idx];
                                }
                            }
                        }
                    }
                }
                // move right
                else
                {
                    // start with the rightmost block
                    for (int j = 0; j < N; j++)
                    {
                        for (int k = N - 1; k > -1; k--)
                        {
                            // a block exists in the coordinate
                            if (map[j][k])
                            {
                                int o_val = map[j][k];
                                map[j][k] = 0;
                                // find where to stop
                                int k_idx = k + 1;
                                int last_idx = k;
                                bool merge = false;
                                while (true)
                                {
                                    if (k_idx >= N)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        int val = map[j][k_idx];
                                        // check for value in new coordinates
                                        // occupied
                                        if (val)
                                        {
                                            // same values
                                            // we can move to j_idx by merging
                                            if (val == o_val)
                                            {
                                                merge = true;
                                                last_idx = k_idx;
                                                break;
                                            }
                                            // different values
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        // we can move to j_idx because its empty
                                        else
                                        {
                                            last_idx = k_idx;
                                        }
                                    }
                                    k_idx++;
                                }
                                if (merge)
                                {
                                    map[j][last_idx] = map[j][last_idx] * 2;
                                }
                                else
                                {
                                    map[j][last_idx] = o_val;
                                }
                                if (map[j][last_idx] > biggest)
                                {
                                    biggest = map[j][last_idx];
                                }
                            }
                        }
                    }
                }
            }
            // move vertically
            else
            {
                // move up
                if (a == -1)
                {
                    for (int k = 0; k < N; k++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            // a block exists in the coordinate
                            if (map[j][k])
                            {
                                int o_val = map[j][k];
                                map[j][k] = 0;
                                // find where to stop
                                int j_idx = j - 1;
                                int last_idx = j;
                                bool merge = false;
                                while (true)
                                {
                                    if (j_idx < 0)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        int val = map[j_idx][k];
                                        // check for value in new coordinates
                                        // occupied
                                        if (val)
                                        {
                                            // same values
                                            // we can move to j_idx by merging
                                            if (val == o_val)
                                            {
                                                merge = true;
                                                last_idx = j_idx;
                                                break;
                                            }
                                            // different values
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        // we can move to j_idx because its empty
                                        else
                                        {
                                            last_idx = j_idx;
                                        }
                                    }
                                    j_idx--;
                                }
                                if (merge)
                                {
                                    map[last_idx][k] = map[last_idx][k] * 2;
                                }
                                else
                                {
                                    map[last_idx][k] = o_val;
                                }
                                if (map[last_idx][k] > biggest)
                                {
                                    biggest = map[last_idx][k];
                                }
                            }
                        }
                    }
                }
                // move down
                else
                {
                    // start with the bottommost block
                    // start with the topmost block
                    for (int k = 0; k < N; k++)
                    {
                        for (int j = N - 1; j > -1; j--)
                        {
                            // a block exists in the coordinate
                            if (map[j][k])
                            {
                                int o_val = map[j][k];
                                map[j][k] = 0;
                                // find where to stop
                                int j_idx = j + 1;
                                int last_idx = j;
                                bool merge = false;
                                while (true)
                                {
                                    if (j_idx >= N)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        int val = map[j_idx][k];
                                        // check for value in new coordinates
                                        // occupied
                                        if (val)
                                        {
                                            // same values
                                            // we can move to j_idx by merging
                                            if (val == o_val)
                                            {
                                                merge = true;
                                                last_idx = j_idx;
                                                break;
                                            }
                                            // different values
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        // we can move to j_idx because its empty
                                        else
                                        {
                                            last_idx = j_idx;
                                        }
                                    }
                                    j_idx++;
                                }
                                if (merge)
                                {
                                    map[last_idx][k] = map[last_idx][k] * 2;
                                }
                                else
                                {
                                    map[last_idx][k] = o_val;
                                }
                                if (map[last_idx][k] > biggest)
                                {
                                    biggest = map[last_idx][k];
                                }
                            }
                        }
                    }
                }
            }
            q.push({cnt + 1, map});
        }
    }
    return biggest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    temp = vector<int>(N, 0);
    arr = vector<vector<int>>(N, temp);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    cout << find_biggest();
}