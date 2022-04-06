#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    int arr[42];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i < 42; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int first = arr[N - 1];
        if (N - 1 == -1)
        {
            first = 1;
        }
        cout << first << " " << arr[N];
        cout << endl;
    }
}