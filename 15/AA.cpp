#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    cout << count;
}