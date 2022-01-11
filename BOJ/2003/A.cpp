#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    int count = 0;
    int p1, p2;
    int last_idx = N - 1;
    p1 = 0;
    p2 = 0;
    int sum = arr[p1];
    while (p1 <= last_idx)
    {
        while (sum < M && p2 <= last_idx)
        {
            sum += arr[++p2];
        }
        //if sum is smaller than M, break
        //it means the above while loop is broken by second condition
        if (sum < M)
        {
            break;
        }
        //if sum matches M
        else if (sum == M)
        {
            sum = sum - arr[p1++];
            count++;
        }
        //if sum is bigger than M
        else
        {
            while (sum > M)
            {
                sum = sum - arr[p1++];
            }
        }
    }
    cout << count;
}