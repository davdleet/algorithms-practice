#include <iostream>
#include <vector>

using namespace std;

vector<int> operators{
    0, 0, 0, 0};
vector<int> arr;
vector<int> visited;
int N;
int max_num = -1000000000;
int min_num = 1000000000;

void DFS(int level, int num)
{
    if (level == N)
    {
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    else
    {
        for (int j = 0; j < 4; j++)
        {
            if (!operators[j])
            {
                continue;
            }

            int new_num = arr[level];
            int next_num = 0;
            switch (j)
            {
            case (0):
            {
                next_num = num + new_num;
                break;
            }
            case (1):
            {
                next_num = num - new_num;
                break;
            }
            case (2):
            {
                next_num = num * new_num;
                break;
            }
            case (3):
            {
                if (new_num < 0)
                {
                    next_num = num / (new_num * -1);
                    next_num = next_num * -1;
                }
                else
                    next_num = num / new_num;
                break;
            }
            default:
                break;
            }
            operators[j]--;
            DFS(level + 1, next_num);
            operators[j]++;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr = vector<int>(N, 0);
    visited = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr[i] = n;
    }

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        operators[i] = n;
    }

    DFS(1, arr[0]);
    cout << max_num << endl;
    cout << min_num << endl;
    return 0;
}