#include <iostream>

using namespace std;

int answer(int x)
{
    int result = 0;
    for (int i = 1; i <= x; i++)
    {
        result += i;
    }
    return result;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int question;
        scanf("%d", &question);
        int answer1 = answer(question);
        int written;
        scanf("%d", &written);
        if (answer1 == written)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}