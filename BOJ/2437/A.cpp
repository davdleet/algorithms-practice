#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int m = INT_MAX;
set<int> sums;
int arr[1000];
int ch[1000];
int N;
int sum = 0;

using namespace std;

void DFS(int num)
{
    if (num == N)
    {
        sums.insert(sum);
        return;
    }
    else
    {
        sum += arr[num];
        DFS(num + 1);
        sum -= arr[num];
        DFS(num + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    DFS(0);
    set<int>::iterator f = sums.begin();
    for (set<int>::iterator it = next(sums.begin(), 1); it != sums.end(); it++)
    {
        int first = *f;
        int second = *it;
        if (second - first != 1)
        {
            cout << first + 1;
            return 0;
        }
        f = next(f, 1);
    }
    cout << *prev(sums.end(), 1);
}