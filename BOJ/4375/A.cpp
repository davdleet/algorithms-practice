#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int num;
    int ones = 1;
    int count = 1;
    while (cin >> num)
    {
        ones = 1;
        count = 1;
        while (1)
        {
            if (ones % num == 0)
            {
                break;
            }
            else
            {
                ones = ones * 10 + 1;
                ones = ones % num;
                count++;
            }
        }
        cout << count << endl;
    }
}