#include <iostream>
#include <queue>
#define INT_MAX 2147483647
using namespace std;
queue<int> q;
int ch[10001];
int path = 0;
int min = INT_MAX;
int d[3] = {-1, 1, 5};

int main()
{
    // freopen("input.txt", "rt", stdin);
    int S, E;
    scanf("%d %d", &S, &E);
    q.push(S);
    ch[S] = 0;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        if (num == E)
        {
            cout << ch[num];
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            if (ch[num + d[i]] == 0)
            {
                ch[num + d[i]] = ch[num] + 1;
                q.push(num + d[i]);
            }
        }
    }
}