#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int A[10] = {0};
    int B[10] = {0};
    int pa = 0;
    int pb = 0;
    for (int i = 0; i < 10; i++)
    {
        int temp;
        scanf("%d", &temp);
        A[i] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        int temp;
        scanf("%d", &temp);
        B[i] = temp;
    }
    char final_winner = '0';
    for (int i = 0; i < 10; i++)
    {
        int ca = A[i];
        int cb = B[i];
        if (ca == cb)
        {
            pa++;
            pb++;
        }
        else if (ca > cb)
        {
            final_winner = 'A';
            pa = pa + 3;
        }
        else
        {
            final_winner = 'B';
            pb = pb + 3;
        }
    }
    cout << pa << " " << pb << endl;
    if (pa == pb)
    {
        if (final_winner == '0')
        {
            cout << "D";
        }
        else
        {
            cout << final_winner;
        }
    }
    else if (pa > pb)
    {
        cout << "A";
    }
    else
    {
        cout << "B";
    }
}