#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    int K;
    cin >> N;
    cin >> K;
    int prince_idx = 0;
    int counter = 0;
    vector<int> arr;
    for (int i = 1; i < N + 1; i++)
    {
        arr.push_back(i);
    }
    int size = arr.size();
    int num = 0;
    while (size > 1)
    {
        int prince_num = arr[prince_idx];
        counter++;
        //cout << "pass " << num << "---" << prince_num << " prince said " << counter << endl;
        if (counter == K)
        {
            counter = 0;
            //cout << "   prince " << arr[prince_idx] << " eliminated!" << endl;
            arr.erase(arr.begin() + prince_idx);
            size--;
        }
        else
        {
            prince_idx++;
        }
        if (prince_idx == arr.size())
        {
            prince_idx = 0;
        }
        num++;
    }
    cout << arr[0];
}