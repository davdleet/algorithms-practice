#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool arr[10];
int start = 100;
int target = 0;
int N;
int M;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./input.txt", "r", stdin);
    cin >> N >> M;
    cout << N << endl;
    cout << M;
    fill_n(arr, 10, 1);
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = false;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}