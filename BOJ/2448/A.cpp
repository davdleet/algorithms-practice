#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> board;

int N;

void tri(int x, int y, int size)
{
    if (size == 3)
    {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        int temp_y = y - 2;
        for (int i = 0; i < 5; i++)
        {
            board[x + 2][temp_y + i] = '*';
        }
        return;
    }
    else
    {
        // first triangle
        tri(x, y, size / 2);
        // second (bottom left)
        tri(x + (size / 2), y - (size / 2), size / 2);
        // third (bottom right)
        tri(x + (size / 2), y + (size / 2), size / 2);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    board = vector<vector<char>>(N, vector<char>(N * 2 - 1, ' '));

    tri(0, N - 1, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}