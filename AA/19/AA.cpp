#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    vector<int> all;
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        all.push_back(temp);
    }
    int count = 0;
    for (int i = 0; i < all.size(); i++)
    {
        int current = all[i];
        bool blocker = true;
        if (i == all.size() - 1)
        {
            blocker = false;
        }
        else
        {
            for (int j = i + 1; j < all.size(); j++)
            {
                if (all[j] >= current)
                {
                    blocker = false;
                    break;
                }
            }
        }
        if (blocker)
        {
            //cout << current << endl;
            count++;
        }
    }
    cout << count;
}