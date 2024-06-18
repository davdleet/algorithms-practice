#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// calculates distance of chicken store to all homes
int calculate(int N, vector<pair<int, int>> *homes, vector<pair<int, int>> *chicken, int x, int y, vector<int> *marked)
{
    // min dis of home to any chicken place
    vector<int> min_dis(homes->size(), 10000000);
    // calculate distance of each chicken house to houses
    for (int i = 0; i < chicken->size(); i++)
    {
        if (!(*marked)[i])
        {
            continue;
        }
        for (int j = 0; j < homes->size(); j++)
        {
            // distance of chicken stre i and home j
            int currentDis = abs((*chicken)[i].first - (*homes)[j].first) + abs((*chicken)[i].second - (*homes)[j].second);
            if (currentDis < min_dis[j])
            {
                min_dis[j] = currentDis;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < min_dis.size(); i++)
    {
        result = result + min_dis[i];
    }
    return result;
}

int DFS(int level, int M, int N, int cnt, vector<pair<int, int>> *homes, vector<pair<int, int>> *chicken, vector<int> *marked)
{
    int result = 100000000;
    if (level == chicken->size())
    {
        for (int i = 0; i < marked->size(); i++)
        {
            if ((*marked)[i])
            {
                result = calculate(N, homes, chicken, (*chicken)[i].first, (*chicken)[i].second, marked);
            }
        }
    }
    else
    {
        // mark current level
        if (cnt < M)
        {
            (*marked)[level] = 1;
            result = min(result, DFS(level + 1, M, N, cnt + 1, homes, chicken, marked));
        }
        (*marked)[level] = 0;
        // advance without marking
        result = min(result, DFS(level + 1, M, N, cnt, homes, chicken, marked));
    }
    return result;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> chicken_dis = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    vector<pair<int, int>> *homes = new vector<pair<int, int>>;
    vector<pair<int, int>> *chicken = new vector<pair<int, int>>;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
            if (temp == 1)
            {
                homes->push_back({i, j});
            }
            else if (temp == 2)
            {
                chicken->push_back({i, j});
            }
        }
    }
    priority_queue<int> pq;
    vector<int> *marked = new vector<int>(chicken->size(), 0);
    int ans = 0;
    ans = DFS(0, M, N, 0, homes, chicken, marked);
    cout << ans;
}