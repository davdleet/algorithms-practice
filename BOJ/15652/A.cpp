#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr(9, 0);
void bruteforce(int size)
{
    if (size == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (size > 0 && i < arr[size - 1])
            {
                continue;
            }
            arr[size] = i;
            bruteforce(size + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    bruteforce(0);
}