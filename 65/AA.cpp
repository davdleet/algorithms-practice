#include <iostream>

using namespace std;

int maze[9][9] = {};
int cnt = 0;
int path[9][9] = {};
void DFS(int i, int j)
{
    if (i == 7 && j == 7)
    {
        cnt++;
    }
    else
    {
        if (maze[i][j + 1] == 0 && path[i][j + 1] == 0)
        {
            path[i][j + 1] = 1;
            DFS(i, j + 1);
            path[i][j + 1] = 0;
        }
        if (maze[i + 1][j] == 0 && path[i + 1][j] == 0)
        {
            path[i + 1][j] = 1;
            DFS(i + 1, j);
            path[i + 1][j] = 0;
        }
        if (maze[i][j - 1] == 0 && path[i][j - 1] == 0)
        {
            path[i][j - 1] = 1;
            DFS(i, j - 1);
            path[i][j - 1] = 0;
        }
        if (maze[i - 1][j] == 0 && path[i - 1][j] == 0)
        {
            path[i - 1][j] = 1;
            DFS(i - 1, j);
            path[i - 1][j] = 0;
        }
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int input;
            if (i == 0 || i == 8 || j == 0 || j == 8)
            {
                input = 1;
            }
            else
            {
                scanf("%d", &input);
            }
            maze[i][j] = input;
        }
    }
    path[1][1] = 1;
    DFS(1, 1);
    cout << cnt;
}