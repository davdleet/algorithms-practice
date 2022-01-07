#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[21];
int ch[21];
int count = 0;
int Q[100];
int front = -1, back = -1;
int dist[21];
int main()
{
    freopen("input.txt", "rt", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        arr[v1].push_back(v2);
    }
    ch[1] = 1;
    Q[++back] = 1;
    while (front < back)
    {
        int num = Q[++front];
        for (int i = 0; i < arr[num].size(); i++)
        {
            if (ch[arr[num][i]] == 0)
            {
                ch[arr[num][i]] = 1;
                Q[++back] = arr[num][i];
                dist[arr[num][i]] = dist[num] + 1;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        cout << i << " : " << dist[i] << endl;
    }
}