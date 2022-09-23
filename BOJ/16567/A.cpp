#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int N, M;
int cnt = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    arr.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);

        if (num)
        {
            if ((i - 1 >= 1 && arr[i - 1]))
            {
                // nothing
            }
            else
            {
                cnt++;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        int ins;
        cin >> ins;
        int idx = -1;
        if (ins)
        {
            cin >> idx;
            bool changed = false;
            if (!arr[idx])
            {
                changed = true;
                arr[idx] = 1;
                if ((idx - 1 >= 0 && arr[idx - 1]) && (idx + 1 <= N && arr[idx + 1]))
                {
                    cnt--;
                }
                else if ((idx - 1 >= 0 && arr[idx - 1]) || (idx + 1 <= N && arr[idx + 1]))
                {
                    // nothing
                }
                else
                {

                    cnt++;
                }
            }
        }
        else
        {
            cout << cnt << "\n";
        }
    }
}