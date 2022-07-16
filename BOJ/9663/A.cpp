#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 15

vector<int> t(MAX_N + 1, 0);
vector<vector<int>> arr(MAX_N + 1, t);
vector<vector<int>> visited(MAX_N + 1, t);
vector<pair<int, int>> queens;
vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int N;
int cnt = 0;

bool test(int x, int y)
{
    bool avail = true;
    for (int i = 0; i < queens.size(); i++)
    {
        int q_x = queens[i].first;
        int q_y = queens[i].second;
        // check if row or cols match
        if (x == q_x || y == q_y)
        {
            avail = false;
            break;
        }
        else if (x - y == q_x - q_y)
        {
            avail = false;
            break;
        }
        else if (x + y == q_x + q_y)
        {
            avail = false;
            break;
        }
    }

    return avail;
}

void printvis()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void bruteforce(int x, int y)
{
    cout << "cnt " << cnt << endl;
    cout << "X AND Y: " << x << " " << y << endl;
    visited[x][y] = 1;
    // printvis();
    bool available = test(x, y);
    if (available)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == x && j == y)
                {
                    cout << "x"
                         << " ";
                }
                else
                {
                    cout << arr[i][j] << " ";
                }
            }
            cout << "\n";
        }
        cout << "place" << endl;
        arr[x][y] = 1;
        queens.push_back(make_pair(x, y));
        if (queens.size() == N)
        {
            cout << "EIGHT" << endl;
            cnt++;
        }
        for (int i = 0; i < dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
        }
        // cout << "pop queen" << endl;
        arr[x][y] = 0;
        queens.pop_back();
        visited[x][y] = 0;
        for (int i = 0; i < dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
        }
    }
    else
    {
        cout << "not avail"
             << "\n";
        for (int i = 0; i < dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
        }
    }
    cout << endl
         << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N;
    cout << "N: " << N << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bruteforce(i, j);
            vector<vector<int>> temp(MAX_N + 1, t);
            vector<pair<int, int>> q;
            queens = q;
            visited = temp;
        }
    }
    cout << "cnt: " << cnt;
}