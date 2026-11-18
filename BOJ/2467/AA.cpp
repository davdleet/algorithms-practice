#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int p1, p2;
    p1 = 0;
    p2 = arr.size() - 1;
    int a_s, a_e;
    int diff = 10000000;
    vector<pair<int, int>> save;
    while (p1 < p2)
    {

        if (abs(arr[p2] + arr[p1]) < diff)
        {
            cout << abs(arr[p2] + arr[p1]) << "smaller than " << diff << endl;
            diff = abs(arr[p2] + arr[p1]);
            a_s = p1;
            a_e = p2;
        }
        if (abs(arr[p2] + arr[p1 + 1]) < abs(arr[p2 - 1] + arr[p1]))
        {
            cout << "p1" << endl;
            p1++;
        }
        else if (abs(arr[p2] + arr[p1 + 1]) == abs(arr[p2 - 1] + arr[p1]))
        {
            cout << "p2" << endl;
            save.push_back({p1 + 1, p2});
            p2--;
        }
        else
        {
            cout << "p2" << endl;
            p2--;
        }
        if (p1 < p2 && save.size())
        {
            pair<int, int> p = save.back();
            save.pop_back();
            p1 = p.first;
            p2 = p.second;
        }
    }
    cout << arr[a_s] << " " << arr[a_e];
}