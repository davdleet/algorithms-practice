#include <iostream>
#include <queue>

using namespace std;

struct order
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    }
};

class absHeap
{
public:
    absHeap()
    {
    }
    void push(int num)
    {
        pq.push({abs(num), num});
    }
    void pop()
    {
        if (pq.size() == 0)
        {
            cout << 0 << "\n";
            return;
        }
        cout << pq.top().second << "\n";
        pq.pop();
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, order> pq;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    absHeap h;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            h.pop();
        }
        else
        {
            h.push(n);
        }
    }
}