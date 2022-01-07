#include <iostream>

using namespace std;

int main()
{
    int N;
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &N);
    int arr[50001] = {0};
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j = j + i)
        {
            arr[j]++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
}