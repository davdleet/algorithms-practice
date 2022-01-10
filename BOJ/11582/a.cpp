#include <iostream>
using namespace std;

int arr[1100000];
int temp[1100000];
int current;
int K;
void mergesort(int l, int r, int num)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergesort(l, m, num * 2);
    mergesort(m + 1, r, num * 2);
    int p1 = l, p2 = m + 1, p3 = l;
    if(num > K){
            while (p1 <= m && p2 <= r)
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
        while (p1 <= m)
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    cin >> K;
    current = N;
    if(K > 1){
        mergesort(1, N, 2);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
}