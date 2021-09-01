#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    int prev = 0;
    int current = 0;
    int count = 0;
    int max = 1;
    for (int i = 0; i < N; i++)
    {
        prev = current;
        scanf("%d", &current);
        if (i == 0 || current >= prev)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > max)
        {
            max = count;
        }
    }
    cout << max;
}