#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    int ten = 10;
    int add = 1;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i >= ten)
        {
            ten = ten * 10;
            add++;
        }
        count = count + add;
    }
    cout << count;
}