#include <iostream>
#include <map>
using namespace std;

int arr[1000000];
int temp[1000000];
int result[1000000];

void merge(int p1, int p2, int p3, int end)
{
    int start = p1;
    int middle = p2 - 1;
    while (p1 <= middle && p2 <= end)
    {
        if (result[p1] < result[p2])
        {
            temp[p3++] = result[p1++];
        }
        else
        {
            temp[p3++] = result[p2++];
        }
    }
    while (p1 <= middle)
    {
        temp[p3++] = result[p1++];
    }
    while (p2 <= end)
    {
        temp[p3++] = result[p2++];
    }
    for (int i = start; i <= end; i++)
    {
        result[i] = temp[i];
    }
}

void mergesort(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int middle = (start + end) / 2;
    mergesort(start, middle);
    mergesort(middle + 1, end);
    int p1 = start;
    int p2 = middle + 1;
    int p3 = start;
    merge(p1, p2, p3, end);
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
        result[i] = temp;
    }
    mergesort(0, N - 1);
    int idx = 0;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        auto it = m.find(result[i]);
        if (it == m.end())
        {
            m.insert({result[i], idx++});
        }
    }
    for (int i = 0; i < N; i++)
    {
        int check = arr[i];
        auto it = m.find(check);
        cout << (*it).second << " ";
    }
}