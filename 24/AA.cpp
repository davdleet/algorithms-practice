#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    while (scanf("%d", &N) != EOF)
    {
        int prev;
        scanf("%d", &prev);
        bool jj = true;
        bool all_found = true;
        vector<int> diffs;
        for (int i = 1; i < N; i++)
        {
            int current;
            scanf("%d", &current);
            int diff = current - prev;
            if (diff < 0)
            {
                diff = diff * -1;
            }
            diffs.push_back(diff);
            if (diff > 0 && diff < N)
            {
            }
            else
            {
                jj = false;
            }
            prev = current;
        }
        sort(diffs.begin(), diffs.end());
        for (int i = 1; i < N; i++)
        {
            if (i != diffs[i - 1])
            {
                all_found = false;
            }
        }
        if (jj && all_found)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}