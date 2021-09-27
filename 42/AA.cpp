#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binsearch(int left, int right, int target, vector<int> arr)
{
    int middle = (left + right) / 2;
    int result;
    if (arr[middle] == target)
    {
        return middle;
    }
    else
    {
        if (target < arr[middle])
        {
            return result = binsearch(left, middle - 1, target, arr);
        }
        else if (target > arr[middle])
        {
            return result = binsearch(middle + 1, right, target, arr);
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int result = binsearch(0, arr.size(), M, arr);
    int result1 = binary_search(arr.begin(), arr.end(), M);
    //built in only checks whether the element exists in the container
    cout << "built in binsearch " << result1 << endl;
    cout << "my binary search " << result + 1;
}