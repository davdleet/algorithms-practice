#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> check;
vector<int> a;
void print(int idx)
{
    check[idx] = 1;
    a.push_back(arr[idx]);
    if (a.size() == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << a[i];
            if (i != M - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!check[i])
            {
                print(i);
            }
        }
    }
    a.pop_back();
    check[idx] = 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    check = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++)
    {
        print(i);
    }
}