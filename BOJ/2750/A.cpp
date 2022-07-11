#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 1000

vector<int> arr;

void merge(int i1, int i2, int end)
{
    vector<int> result;
    int idx_1 = i1;
    int idx_2 = i2;
    while (true)
    {
        if (idx_1 == i2 || idx_2 == end + 1)
        {
            break;
        }
        if (arr[idx_1] <= arr[idx_2])
        {
            result.push_back(arr[idx_1++]);
        }
        else
        {
            result.push_back(arr[idx_2++]);
        }
    }
    while (idx_1 != i2)
    {
        result.push_back(arr[idx_1++]);
    }
    while (idx_2 != end + 1)
    {
        result.push_back(arr[idx_2++]);
    }
    int r_idx = 0;
    for (int i = i1; i <= end; i++)
    {
        arr[i] = result[r_idx++];
    }
}

void mergesort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m + 1, r);
    }
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
    mergesort(0, arr.size() - 1);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}