#include <iostream>

using namespace std;

int main()
{
    int A, B, sum = 0;
    int i;
    cin >> A >> B;
    for (i = A; i < B; i++)
    {
        cout << i << " + ";
        sum += i;
    }
    cout << i << " = ";
    sum += i;
    cout << sum;
}