#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void quicksort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int start = l;
    int end = r;
    int pivot = l;
    int m;
    l = l + 1;
    while (l <= r)
    {
        while (l <= end && arr[l] <= arr[pivot])
        {
            l++;
        }
        while (r > start && arr[r] >= arr[pivot])
        {
            r--;
        }
        if (l > r)
        {
            int temp;
            temp = arr[pivot];
            arr[pivot] = arr[r];
            arr[r] = temp;
            int m = r;
        }
        else
        {
            int temp;
            temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }
    }
    quicksort(start, m - 1);
    quicksort(m + 1, end);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    quicksort(0, arr.size() - 1);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
}