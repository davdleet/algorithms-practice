#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 15

vector<int> t(MAX_N + 1, 0);
vector<vector<int> > arr(MAX_N + 1, t);
vector<vector<int> > visited(MAX_N + 1, t);
vector<pair<int, int> > queens;
vector<pair<int, int> > dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int N;
int cnt = 0;

bool test(int x, int y)
{
    bool avail = true;
    for (int i = 0; i < queens.size(); i++)
    {
        int q_x = queens[i].first;
        int q_y = queens[i].second;
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
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void bruteforce(int x, int y)
{
    cout << x << " " << y << endl;
    visited[x][y] = 1;
    printvis();
    if (test(x, y))
    {
        cout << "place" << endl;
        arr[x][y] = 1;
        queens.push_back(make_pair(x, y));
        if (queens.size() == N)
        {
            cnt++;
        }
        for (int i = 0; dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            cout << x + a << " " << y + b << endl;
            cout << "test1" << endl;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
            cout << "end test" << endl;
        }
        arr[x][y] = 0;
        queens.pop_back();
        for (int i = 0; dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            cout << x + a << " " << y + b << endl;
            cout << "test2" << endl;
            cout << "visited: " << visited[x + a][y + b] << endl;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
            cout << "end test" << endl;
        }
    }
    else
    {
        for (int i = 0; dir.size(); i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            cout << x + a << " " << y + b << endl;
            cout << "test3" << endl;
            cout << "visited: " << visited[x + a][y + b] << endl;
            cout << (visited[x + a][y + b] == 0) << endl;
            if ((x + a > 0) && (x + a <= N) && (y + b > 0) && (y + b <= N) && (visited[x + a][y + b] == 0))
            {
                bruteforce(x + a, y + b);
            }
            cout << "end test" << endl;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N;
    visited[1][1] = 1;
    cout << visited[1][1] << endl;
    cout << arr[1][1] << endl;
    // bruteforce(1, 1);
    cout << cnt;
}