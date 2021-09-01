#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int max = 0;
    int duration = 0;
    for (int i = 0; i < N; i++)
    {
        int sound;
        scanf("%d", &sound);
        if (sound > M)
        {
            duration++;
            if (duration > max)
            {
                max = duration;
            }
        }
        else
        {
            duration = 0;
        }
    }
    cout << max;
}