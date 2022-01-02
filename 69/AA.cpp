#include <iostream>
#include <vector>

using namespace std;

int Q[100];
int front = -1, back = -1;
vector<int> map[20];
int ch[20] = {};

int main()
{
    freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 6; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        map[v1].push_back(v2);
        map[v2].push_back(v1);
    }
    ch[1] = 1;
    Q[++back] = 1;
    while (front < back)
    {
        int x = Q[++front];
        printf("%d ", x);
        for (int i = 0; i < map[x].size(); i++)
        {
            if (ch[map[x][i]] == 0)
            {
                ch[map[x][i]] = 1;
                Q[++back] = map[x][i];
            }
        }
    }
}