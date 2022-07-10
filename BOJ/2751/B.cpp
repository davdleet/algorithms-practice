#include <iostream>
#include <vector>

#define MAX_NUM 1000001

using namespace std;

vector<int> arr_pos(MAX_NUM, 0);
vector<int> arr_neg(MAX_NUM, 0);

// approach with counting sort
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
        if (temp >= 0)
        {
            arr_pos[temp]++;
        }
        else
        {
            arr_neg[abs(temp)]++;
        }
    }
    for (int i = MAX_NUM - 1; i > 0; i--)
    {
        if (!arr_neg[i])
        {
            continue;
        }
        else
        {
            cout << -i << "\n";
        }
    }
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (!arr_pos[i])
        {
            continue;
        }
        else
        {
            cout << i << "\n";
        }
    }
}