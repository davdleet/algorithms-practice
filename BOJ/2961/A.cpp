#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<long long int, long long int>> arr;
vector<bool> check;
int N;
long long int diff = 20000000000;

void bruteforce(int idx)
{
    long long int mul = 1;
    long long int sum = 0;
    if (idx == N + 1)
    {
        bool found = false;
        for (int i = 0; i < N; i++)
        {
            if (check[i])
            {
                found = true;
                mul *= arr[i].first;
                sum += arr[i].second;
            }
        }
        if (found)
        {
            diff = min(diff, abs(mul - sum));
        }
        return;
    }
    bruteforce(idx + 1);
    check[idx] = 1;
    bruteforce(idx + 1);
    check[idx] = 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        check.push_back(0);
        long long int s, b;
        cin >> s >> b;
        pair<long long int, long long int> temp = {s, b};
        arr.push_back(temp);
    }
    bruteforce(0);
    cout << diff;
}