#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x)
{
    // Corner case
    if (x <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;

    return true;
}
/*
bool isPrime(int x)
{
    if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0 && x % 7 != 0 && x % 11 != 0 && x % 13 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/

int reverse(int x)
{
    int res = 0;
    while (x > 0)
    {
        int tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }
    return res;
}

int main()
{
    int N;
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &N);
    bool first = true;
    for (int i = 0; i < N; i++)
    {
        int number;
        scanf("%d", &number);
        int reversed = reverse(number);
        if (isPrime(reversed))
        {
            /*
            if (first)
            {
                cout << reversed;
                first = false;
            }
            else
            {
                cout << " " << reversed;
            }*/
            cout << reversed << " ";
        }
    }
}