#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

// quicksort is too slow as it has O^2 time complexity
void quicksort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int end = r;
    int pivot = l;
    l++;
    while (l <= r)
    {
        while (l <= end && arr[l] <= arr[pivot])
        {
            l++;
        }
        while (r > pivot && arr[r] >= arr[pivot])
        {
            r--;
        }
        if (l > r)
        {
            int temp;
            temp = arr[pivot];
            arr[pivot] = arr[r];
            arr[r] = temp;
        }
        else
        {
            int temp;
            temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }
    }
    quicksort(pivot, r - 1);
    quicksort(r + 1, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    quicksort(0, N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}