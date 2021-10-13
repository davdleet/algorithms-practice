#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int H;
    int W;
    cin >> H;
    cin >> W;
    vector<vector<int>> total_land;
    for (int i = 0; i < H; i++)
    {
        vector<int> temp;
        total_land.push_back(temp);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int temp;
            cin >> temp;
            total_land[i].push_back(temp);
        }
    }
    int my_H;
    int my_W;
    cin >> my_H;
    cin >> my_W;
    int max = 0;
    for (int i = 0; i < H - my_H + 1; i++)
    {
        for (int j = 0; j < W - my_W + 1; j++)
        {
            int current_total = 0;

            for (int k = i; k < i + my_H; k++)
            {
                for (int l = j; l < j + my_W; l++)
                {
                    current_total += total_land[k][l];
                }
            }
            if (current_total > max)
            {
                max = current_total;
            }
        }
    }
    cout << max;
}