#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class score_count
{
    int score;
    int count;

public:
    score_count(int score1, int count1)
    {
        score = score1;
        count = count1;
    }
    int get_score()
    {
        return score;
    }
    int get_count()
    {
        return count;
    }
    void add_count()
    {
        count++;
    }
};

bool compare(score_count a, score_count b)
{
    return a.get_score() > b.get_score();
}

main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    vector<score_count> arr;
    vector<int> arr1;
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        arr1.push_back(num);
        if (arr.size() == 0)
        {
            score_count obj = score_count(num, 1);
            arr.push_back(obj);
        }
        else
        {
            bool existing = false;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j].get_score() == num)
                {
                    existing = true;
                    arr[j].add_count();
                }
            }
            if (!existing)
            {
                arr.push_back(score_count(num, 1));
                sort(arr.begin(), arr.end(), compare);
            }
        }
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        int current = arr1[i];
        int rank = 1;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j].get_score() == current)
            {
                cout << rank << " ";
                break;
            }
            else
            {
                rank += arr[j].get_count();
            }
        }
    }
}