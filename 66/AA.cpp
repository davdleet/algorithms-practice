#include <iostream>
#include <vector>
using namespace std;

vector<int> map[30];
int cnt = 0;
int target;
int visited[30] = {};

void DFS(int num)
{
    if (num == target)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < map[num].size(); i++)
        {
            if (visited[map[num][i]] == 0)
            {
                visited[map[num][i]] = 1;
                DFS(map[num][i]);
                visited[map[num][i]] = 0;
            }
        }
    }
}

int main()
{
    int N, M;
    freopen("input.txt", "rt", stdin);
    scanf("%d %d", &N, &M);
    target = N;
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        map[temp1].push_back(temp2);
    }
    visited[1] = 1;
    DFS(1);
    printf("%d", cnt);
}