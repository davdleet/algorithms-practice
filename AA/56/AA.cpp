#include <iostream>

using namespace std;

int printnum(int num)
{
    if (num == 1)
    {
        cout << num << " ";
    }
    else
    {
        printnum(num - 1);
        cout << num << " ";
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    printnum(N);
}