#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int R, C, T;
    cin >> R >> C >> T;
    vector<vector<int>> room = vector<vector<int>>(R, vector<int>(C, 0));

    vector<pair<int, int>> purifiers;
    pair<int, int> purifier1 = {0, 0};
    pair<int, int> purifier2 = {0, 0};
    bool init = false;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1 && !init)
            {
                purifier1 = {i, j};
                purifier2 = {i + 1, j};
                init = true;
            }
        }
    }
    purifiers.push_back(purifier1);
    purifiers.push_back(purifier2);
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<pair<int, int>> air_up = {{0, 1},
                                     {-1, 0},
                                     {0, -1},
                                     {1, 0}};
    vector<pair<int, int>> air_down = {{0, 1},
                                       {1, 0},
                                       {0, -1},
                                       {-1, 0}};
    vector<vector<pair<int, int>>> air_dirs;
    air_dirs.push_back(air_up);
    air_dirs.push_back(air_down);

    for (int t = 0; t < T; t++)
    {
        vector<vector<int>> spread_next = vector<vector<int>>(R, vector<int>(C, 0));
        // 1. 확산
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {

                int spread_cnt = 0;
                int spread_amt = int(room[i][j] / 5);
                for (int p_idx = 0; p_idx < dir.size(); p_idx++)
                {
                    pair<int, int> p = dir[p_idx];
                    int a = p.first;
                    int b = p.second;
                    // check if within bounds
                    if (i + a >= 0 && i + a < R && j + b >= 0 && j + b < C && room[i + a][j + b] != -1)
                    {
                        spread_next[i + a][j + b] = spread_next[i + a][j + b] + spread_amt;
                        spread_cnt++;
                    }
                }
                room[i][j] = room[i][j] - spread_amt * spread_cnt;
            }
        }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                room[i][j] += spread_next[i][j];
            }
        }

        // 2. 공기 청정기
        for (int p = 0; p < purifiers.size(); p++)
        {
            vector<vector<int>> after_air = vector<vector<int>>(R, vector<int>(C, 0));
            pair<int, int> moving_air;
            moving_air = {purifiers[p].first, purifiers[p].second};
            int airdir = 0;

            moving_air.first += air_dirs[p][airdir].first;
            moving_air.second += air_dirs[p][airdir].second;
            while (moving_air.first != purifiers[p].first || moving_air.second != purifiers[p].second)
            {
                int x = moving_air.first;
                int y = moving_air.second;
                int a = air_dirs[p][airdir].first;
                int b = air_dirs[p][airdir].second;
                if (!(x + a >= 0 && x + a < R && y + b >= 0 && y + b < C))
                {
                    airdir++;
                    a = air_dirs[p][airdir].first;
                    b = air_dirs[p][airdir].second;
                }

                // if location is purifier, dont add more dust
                if (x + a == purifiers[p].first && y + b == purifiers[p].second)
                {
                    room[x][y] = 0;
                }
                else
                {
                    // move dust
                    after_air[x + a][y + b] = room[x][y];
                    // empty current spot
                    room[x][y] = 0;
                }
                moving_air.first = x + a;
                moving_air.second = y + b;
            }
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    room[i][j] += after_air[i][j];
                }
            }
        }
    }
    int ans = 2;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans += room[i][j];
        }
    }
    cout << ans;
}