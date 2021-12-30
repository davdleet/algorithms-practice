#include <iostream>
#include <vector>
using namespace std;

int arr[21][21] = {};
int treesize;
int path[21] = {};
int cnt = 0;
void tree(int level)
{
    if (level == treesize)
    {
        cnt++;
    }
    else
    {
        for (int i = 2; i <= treesize; i++)
        {
            if (arr[level][i] == 1 && path[i] == 0)
            {
                path[i] = 1;
                tree(i);
                path[i] = 0;
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    treesize = N;
    for (int i = 0; i < M; i++)
    {
        int node;
        int vertex;
        scanf("%d %d", &node, &vertex);
        arr[node][vertex] = 1;
    }
    path[1] = 1;
    tree(1);
    cout << cnt;
}