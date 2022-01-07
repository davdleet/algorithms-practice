#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int max = 2;
    int min = 100;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
    }
    cout << max - min;
}