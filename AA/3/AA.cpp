#include <iostream>

using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    cout << 1;
    sum += 1;
    for (int i = 2; i < N; i++)
    {
        if (N % i == 0)
        {
            sum += i;
            cout << " + " << i;
        }
    }
    cout << " = " << sum;
}