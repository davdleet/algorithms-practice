#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N, M;
    int arr[20][20] = {};
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int from, to, dist;
        scanf("%d %d %d", &from, &to, &dist);
        arr[from - 1][to - 1] = dist;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}