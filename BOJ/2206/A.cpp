#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAX 1000

vector<char> temp;
vector<int> temp1;
vector<vector<char>> arr;
int visited[MAX + 1][MAX + 1][2];

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M;

class visit
{
public:
    int x;
    int y;
    bool charge;
    visit(int a, int b, bool c)
    {
        x = a;
        y = b;
        charge = c;
    }
};

int BFS(int x, int y)
{
    queue<visit> q;
    visited[x][y][1] = 1;
    visit f = visit(x, y, true);
    int ans = -1;
    q.push(f);
    while (q.size())
    {
        visit current = q.front();
        q.pop();
        if (current.x == N && current.y == M)
        {
            ans = visited[N][M][current.charge];
            break;
        }
        // move up, down, left, right
        for (int i = 0; i < 4; i++)
        {
            int a = dir[i].first;
            int b = dir[i].second;
            int next_x = current.x + a;
            int next_y = current.y + b;
            // out of bounds
            if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > M)
            {
                continue;
            }
            // if next_x and next_y is a wall but there is charge left
            if ((arr[next_x][next_y] == '1') && current.charge)
            {
                visited[next_x][next_y][current.charge - 1] = visited[current.x][current.y][current.charge] + 1;
                visit next = visit(next_x, next_y, current.charge - 1);
                q.push(next);
            }
            // next is empty and not visited
            if ((arr[next_x][next_y] == '0') && !visited[next_x][next_y][current.charge])
            {
                visited[next_x][next_y][current.charge] = visited[current.x][current.y][current.charge] + 1;
                visit next = visit(next_x, next_y, current.charge);
                q.push(next);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    temp = vector<char>(M + 1, '0');
    arr = vector<vector<char>>(N + 1, temp);
    for (int i = 1; i <= N; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = line[j - 1];
        }
    }
    int ans = BFS(1, 1);
    cout << ans;
}