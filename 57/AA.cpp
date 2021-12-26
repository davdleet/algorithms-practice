#include <iostream>

using namespace std;

int binary(int num)
{
    int leftover = num % 2;
    int result = num / 2;
    if (result == 0)
    {
        cout << leftover;
        return 0;
    }
    else
    {
        binary(result);
        cout << leftover;
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    binary(N);
}