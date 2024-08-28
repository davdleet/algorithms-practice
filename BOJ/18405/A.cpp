#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<queue<pair<int, int>>> q_arr(K + 1, queue<pair<int, int>>());
    bool q_filled;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = num;
            if (num)
            {
                q_arr[num].push({i, j});
                q_filled = true;
            }
        }
    }
    int S, X, Y;
    cin >> S >> X >> Y;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int s = 0; s < S; s++)
    {
        for (int i = 1; i < q_arr.size(); i++)
        {
            // for queue number: i
            int q_size = q_arr[i].size();
            for (int i_i = 0; i_i < q_size; i_i++)
            {
                pair<int, int> current = q_arr[i].front();
                q_arr[i].pop();
                int x = current.first;
                int y = current.second;
                for (int j = 0; j < dir.size(); j++)
                {
                    int a = dir[j].first;
                    int b = dir[j].second;
                    if (x + a >= 1 && x + a <= N && y + b >= 1 && y + b <= N && arr[x + a][y + b] == 0)
                    {
                        q_arr[i].push({x + a, y + b});
                        arr[x + a][y + b] = i;
                    }
                }
            }
        }

        // check if queue is empty
        q_filled = false;
        for (int i = 0; i < q_arr.size(); i++)
        {
            if (q_arr[i].size())
            {
                q_filled = true;
            }
        }
    }
    cout << arr[X][Y];
}