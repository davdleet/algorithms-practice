#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    vector<int> arr;
    arr.push_back(1);
    int count = 1;
    int p2 = 1;
    int p3 = 1;
    int p5 = 1;
    int input;
    cin >> input;
    while (count != input)
    {
        int min;
        int mul2, mul3, mul5;
        mul2 = 2 * arr[p2 - 1];
        mul3 = 3 * arr[p3 - 1];
        mul5 = 5 * arr[p5 - 1];
        if (mul2 < mul3)
        {
            min = mul2;
        }
        else
        {
            min = mul3;
        }
        if (mul5 < min)
        {
            min = mul5;
        }
        if (mul2 == min)
            p2++;
        if (mul3 == min)
            p3++;
        if (mul5 == min)
            p5++;
        arr.push_back(min);
        count++;
    }
    cout << arr[arr.size() - 1];
}