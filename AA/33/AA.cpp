#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    vector<int> arr;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        int biggest_score = arr[i];
        int biggest_idx = i;
        for (int j = i; j < N; j++)
        {
            if (arr[j] > biggest_score)
            {
                biggest_score = arr[j];
                biggest_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[biggest_idx];
        arr[biggest_idx] = temp;
    }
    /*
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }*/
    //cout << endl;
    int placement = 1;
    int current_score = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] != current_score)
        {
            placement++;
        }
        if (placement == 3)
        {
            cout << arr[i];
            break;
        }
        current_score = arr[i];
    }
}