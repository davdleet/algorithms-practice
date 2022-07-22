#include <iostream>
#include <vector>
using namespace std;

long long N;
long long M;
long long sum;
// vector<long long> arr;
long long arr[1000002];

int verify(long long num)
{
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long val = arr[i];
        long long add = 0;
        if (val > num)
        {
            add = val - num;
        }
        ans += add;
        // ans is bigger than M
        if (ans > M)
        {
            return 1;
        }
    }
    // ans is M
    if (ans == M)
    {
        return 0;
    }
    // ans is smaller than M
    else
    {
        return -1;
    }
}

long long binary_search(long long start, long long end)
{
    long long ans = -1;
    long long middle = (start + end + 1) / 2;
    int result = verify(middle);
    // middle can be bigger
    if (result == 1)
    {
        ans = middle;
        return max(ans, binary_search(middle + 1, end));
    }
    // middle should be smaller
    else if (result == -1)
    {
        return binary_search(start, middle - 1);
    }
    // middle is exactly m
    else
    {
        return middle;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        sum += temp;
        // arr.push_back(temp);
        arr[i] = temp;
    }
    // cout << binary_search(0, 3000000000);
    long long start, end;
    start = 0;
    end = 3000000000;
    long long ans = -1;
    while (start <= end)
    {
        long long current_ans = -1;
        long long middle = (start + end + 1) / 2;
        int result = verify(middle);
        if (result == 1)
        {
            current_ans = middle;
            ans = max(current_ans, ans);
            start = middle + 1;
        }
        // middle should be smaller
        else if (result == -1)
        {
            end = middle - 1;
        }
        // middle is exactly m
        else
        {
            current_ans = middle;
            ans = max(current_ans, ans);
            break;
        }
    }
    cout << ans;
}