#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> ans;
vector<bool> check;
deque<int> arr;

int N;

bool test()
{
    for (int i = 0; i < N; i++)
    {
        int a_cnt = ans[arr[i] - 1];
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                cnt++;
            }
        }
        if (cnt != a_cnt)
        {
            return false;
        }
    }
    return true;
}

void bruteforce(int size)
{
    if (size == N)
    {
        bool result = test();
        if (result)
        {
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (check[i])
            {
                continue;
            }
            else
            {
                arr.push_back(i + 1);
                check[i] = true;
                bruteforce(size + 1);
                arr.pop_back();
                check[i] = false;
            }
        }
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
        check.push_back(0);
        int temp;
        cin >> temp;
        ans.push_back(temp);
    }
    bruteforce(0);
}