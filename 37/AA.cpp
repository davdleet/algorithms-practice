#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input1.txt", "rt", stdin);
    int S, N;
    cin >> S;
    cin >> N;
    deque<int> arr;
    for (int i = 0; i < S; i++)
    {
        arr.push_back(0);
    }
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        deque<int>::iterator found = find(arr.begin(), arr.end(), input);
        if (found == arr.end())
        {
            arr.push_front(input);
        }
        else
        {
            if (found - arr.begin() == 0)
            {
            }
            else
            {
                arr.erase(found);
                arr.push_front(input);
            }
        }
        if (arr.size() > S)
        {
            arr.pop_back();
        }
    }
    for (int j = 0; j < arr.size(); j++)
    {
        cout << arr[j] << " ";
    }
}