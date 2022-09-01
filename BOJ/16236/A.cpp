#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class point
{
public:
    int x;
    int y;
    int dis;
    point(int a, int b, int c)
    {
        x = a;
        y = b;
        dis = c;
    }
};

vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
vector<vector<int>> arr;
vector<vector<int>> check;
vector<point> nxt;
vector<int> temp;
queue<point> *q;

bool mysort(point a, point b)
{
    if (a.x < b.x)
    {
        return true;
    }
    else if (a.x == b.x)
    {
        if (a.y < b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    temp = vector<int>(N, 0);
    arr = vector<vector<int>>(N, temp);
    check = vector<vector<int>>(N, temp);
    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            arr[i][j] = n;
            if (n == 9)
            {
                x = i;
                y = j;
            }
        }
    }
    bool help = false;
    int eaten = 0;
    int size = 2;
    int time = 0;
    arr[x][y] = 0;
    while (!help)
    {
        q = new queue<point>;
        point initial = point(x, y, 0);
        q->push(initial);
        check = vector<vector<int>>(N, temp);
        check[x][y] = 1;
        nxt = vector<point>();
        int closest = -1;
        while (q->size())
        {
            point current = q->front();
            q->pop();
            // check if there is a fish on current point available to eat
            if (arr[current.x][current.y] > 0 && arr[current.x][current.y] < size)
            {
                if (closest == -1)
                {
                    closest = current.dis;
                }
                else if (closest != -1 && current.dis > closest)
                {
                    break;
                }
                nxt.push_back(current);
                // arr[current.x][current.y] = 0;
                // eaten++;
                // // increase baby shark size
                // if (eaten == size)
                // {
                //     size++;

                //     eaten = 0;
                // }
            }
            for (int i = 0; i < 4; i++)
            {
                int a = dir[i].first;
                int b = dir[i].second;
                if (current.x + a >= 0 && current.x + a < N && current.y + b >= 0 && current.y + b < N && !check[current.x + a][current.y + b] && arr[current.x + a][current.y + b] <= size)
                {
                    check[current.x + a][current.y + b] = 1;
                    point temp_point = point(current.x + a, current.y + b, current.dis + 1);
                    q->push(temp_point);
                }
            }
        }
        if (!nxt.size())
        {
            help = true;
        }
        else
        {
            sort(nxt.begin(), nxt.end(), mysort);
            point eat = nxt[0];
            arr[eat.x][eat.y] = 0;
            time += eat.dis;
            eaten++;
            // increase baby shark size
            if (eaten == size)
            {
                size++;
                eaten = 0;
            }
            x = eat.x;
            y = eat.y;
        }
        free(q);
    }
    cout << time;
}