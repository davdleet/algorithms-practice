#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, K, M;
    cin >> N >> K >> M;
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        int num = i + 1;
        q.push_back(num);
    }
    int n = 0;
    int k = 0;
    int m = 0;
    bool l_to_r = true;
    while (n != N)
    {
        if (k == K - 1)
        {
            int remove;
            if (l_to_r)
            {
                remove = q.front();
                q.pop_front();
            }
            else
            {
                remove = q.back();
                q.pop_back();
            }
            ans.push_back(remove);
            m++;
            if (m == M)
            {
                l_to_r = 1 - l_to_r;
                m = 0;
            }
            n++;
            k = 0;
        }
        else
        {
            int remove;
            if (l_to_r)
            {
                remove = q.front();
                q.pop_front();
                q.push_back(remove);
            }
            else
            {
                remove = q.back();
                q.pop_back();
                q.push_front(remove);
            }
            k++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << "\n";
    }
}