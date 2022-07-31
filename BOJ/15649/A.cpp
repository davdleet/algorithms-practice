#include <iostream>
#include <vector>
#include <string>
#define MAX 9
using namespace std;
int N, M;

// vector<bool> check;
//  vector<int> arr;
int arr[MAX] = {
    0,
};
bool check[MAX] = {
    0,
};
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
            int num = i;
            if (check[num])
            {
                continue;
            }
            check[num] = true;
            arr[size] = num;
            bruteforce(size + 1);
            check[num] = false;
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