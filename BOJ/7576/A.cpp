#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS();

int N, M;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> arr;

class values
{
public:
    int first;
    int second;
    int third;
    values(int f, int s, int t)
    {
        first = f;
        second = s;
        third = t;
    }
};

main()
{
    freopen("input.txt", "rt", stdin);
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        vector<int> temp_vec;
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            temp_vec.push_back(temp);
        }
        arr.push_back(temp_vec);
    }
    int day = 0;
    cout << "test" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << BFS() << endl;
}

int BFS()
{
    int ans = 0;
    bool already_ripe = false;
    queue<values> q;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j] == 0)
            {
                values t = values(i, j, 0);
                q.push(t);
                already_ripe = false;
            }
        }
    }

    if (already_ripe)
    {
        return 0;
    }

    while (q.size() != 0)
    {
        values current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        int d = current.third;
        ans = d;
        cout << ans << endl;
        for (int i = 0; i < dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if ((x + a < 0 || x + a >= N) || (y + b < 0 || y + b >= M) || (arr[x + a][y + b] != 0))
            {
                continue;
            }
            arr[x + a][y + b] = 1;
            values t = values(x + a, y + b, d + 1);
            q.push(t);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        bool break_flag = false;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return ans;
}