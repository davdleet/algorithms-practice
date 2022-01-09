#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = (temp);
    }
    sort(arr.begin(), arr.end());
    int biggest_idx = N - 1;

    int p1 = 0, p2 = 1;
    int max_sides = -1;
    int two_sides = 0;
    while (1)
    {
        if (p1 == p2)
        {
            if (max_sides != -1 || biggest_idx == 2)
            {
                break;
            }
            biggest_idx--;
            p1 = 0;
            p2 = 1;
        }
        int two_sides = arr[p1] + arr[p2];
        if (two_sides > arr[biggest_idx])
        {
            if (max_sides < two_sides + arr[biggest_idx])
            {
                max_sides = two_sides + arr[biggest_idx];
            }
        }
        if (p1 != p2 - 1)
        {
            p1++;
        }
        else
        {
            if (p2 != biggest_idx - 1)
            {
                p2++;
            }
            else
            {
                p1++;
            }
        }
    }
    cout << max_sides;
}