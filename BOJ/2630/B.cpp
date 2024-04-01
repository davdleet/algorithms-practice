#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<vector<double>> t{
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1}};
pair<int, int> cut(int size, int x, int y)
{
    if (size == 1)
    {
        return vec[x][y] == 1 ? make_pair(0, 1) : make_pair(1, 0);
    }

    int newSize = size / 2;
    pair<int, int> result(0, 0);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + (i / 2) * newSize;
        int ny = y + (i % 2) * newSize;
        auto partResult = cut(newSize, nx, ny);
        result.first += partResult.first;
        result.second += partResult.second;
    }

    // If all parts are the same color, consolidate the count
    if (result.first == 4 && result.second == 0)
    {
        return make_pair(1, 0); // All parts are white
    }
    else if (result.second == 4 && result.first == 0)
    {
        return make_pair(0, 1); // All parts are blue
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vec = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            vec[i][j] = num;
        }
    }
    pair<int, int> ans;
    ans = cut(N, 0, 0);
    cout << ans.first << endl
         << ans.second;
}