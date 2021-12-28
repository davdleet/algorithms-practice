#include <iostream>

using namespace std;

int arr[101];

void divide(int l, int r)
{
    if (l < r)
    {
        int p1, p2, p3;
        int mid;
        int temp[101];
        mid = (l + r) / 2;
        p1 = l;
        p2 = mid + 1;
        p3 = l;
        divide(l, mid);
        divide(mid + 1, r);
        while (p1 <= mid && p2 <= r)
        {
            if (arr[p1] < arr[p2])
            {
                temp[p3++] = arr[p1++];
            }
            else
            {
                temp[p3++] = arr[p2++];
            }
        }
        while (p1 <= mid)
        {
            temp[p3++] = arr[p1++];
        }
        while (p2 <= r)
        {
            temp[p3++] = arr[p2++];
        }
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i];
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    divide(1, N);
    for (int i = 1; i < N + 1; i++)
    {
        cout << arr[i] << " ";
    }
}