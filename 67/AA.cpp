#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647
int arr[21][21] = {};
int visited[21] = {};
int shortest = INT_MAX;
int treesize;
int current_path = 0;

void DFS(int num)
{
    if (num == treesize)
    {
        if (current_path < shortest)
        {
            shortest = current_path;
        }
    }
    else
    {
        for (int i = 1; i <= treesize; i++)
        {
            if (arr[num][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                current_path = current_path + arr[num][i];
                DFS(i);
                visited[i] = 0;
                current_path = current_path - arr[num][i];
            }
        }
    }
}

int main()
{
    int N, M;
    // freopen("input.txt", "rt", stdin);
    scanf("%d %d", &N, &M);
    treesize = N;
    for (int i = 0; i < M; i++)
    {
        int v1, v2, v3;
        scanf("%d %d %d", &v1, &v2, &v3);
        arr[v1][v2] = v3;
    }
    visited[1] = 1;
    DFS(1);
    cout << shortest;
}