#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    vector<int> ans;
    while (true)
    {
        int a_max;
        int b_max;
        int ai, bi;
        bool break_flag = false;
        while (true)
        {
            if (a.empty() || b.empty())
            {
                break_flag = true;
                break;
            }
            ai = max_element(a.begin(), a.end()) - a.begin();
            a_max = *max_element(a.begin(), a.end());
            bi = max_element(b.begin(), b.end()) - b.begin();
            b_max = *max_element(b.begin(), b.end());
            if (a_max == b_max)
            {
                break;
            }
            else if (a_max > b_max)
            {
                a.erase(a.begin() + ai);
            }
            else
            {
                b.erase(b.begin() + bi);
            }
        }
        if (break_flag)
        {
            break;
        }
        ans.push_back(a_max);
        int temp = 0;
        for (int i = ai + 1; i < a.size(); i++)
        {
            a[temp] = a[i];
            temp++;
        }
        for (int i = 0; i < ai + 1; i++)
        {
            a.pop_back();
        }
        temp = 0;
        for (int i = bi + 1; i < b.size(); i++)
        {
            b[temp] = b[i];
            temp++;
        }
        for (int i = 0; i < bi + 1; i++)
        {
            b.pop_back();
        }
    }
    if (!ans.empty())
    {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << 0;
    }
}