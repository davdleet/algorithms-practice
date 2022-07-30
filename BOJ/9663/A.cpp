#include <iostream>
#define MAX 15
using namespace std;

int cols[MAX];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
        if (cols[i] == cols[level] || abs(cols[level] - cols[i]) == level - i)
            return false;
    return true;
}

void bruteforce(int x)
{
    if (x == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            cols[x] = i;
            if (check(x))
                bruteforce(x + 1);
        }
    }
}
int main()
{
    cin >> N;
    bruteforce(0);
    cout << total;
}