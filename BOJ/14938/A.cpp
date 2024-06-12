#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    int t;
    vector<vector<pair<int, int>>> distance(n + 1, vector<pair<int, int>>());
    vector<int> arr(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        distance[a].push_back({b, l});
        distance[b].push_back({a, l});
    }
    int max_items = 0;
    // start from i location
    for (int i = 1; i < n + 1; i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({0, i});
        vector<int> dist(n + 1, INT_MAX);
        dist[i] = 0;
        vector<bool> visited(n + 1, false);
        // sum of items you can get if you start from i
        int items = 0;
        while (pq.size())
        {
            pair<int, int> current = pq.top();
            int location = current.second;
            int from_start = current.first;
            pq.pop();

            if (visited[location])
                continue;
            visited[location] = true;

            items += arr[location];
            for (auto &edge : distance[location])
            {
                int next_location = edge.first;
                int travel_cost = edge.second;
                if (travel_cost + from_start <= m && travel_cost + from_start < dist[next_location])
                {
                    dist[next_location] = travel_cost + from_start;
                    pq.push({travel_cost + from_start, next_location});
                }
            }
            if (items > max_items)
            {
                max_items = items;
            }
        }
    }
    cout << max_items << endl;
}