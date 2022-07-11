#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class coords
{

public:
    int x;
    int y;
    coords(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool compare(coords a, coords b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    vector<coords> arr;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        coords temp = coords(x, y);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
}