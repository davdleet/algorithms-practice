#include <queue>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    map<string, map<string, int>> distance;
    vector<string> mbti{"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"};
    for (int i = 0; i < mbti.size(); i++)
    {
        string current = mbti[i];
        for (int j = 0; j < mbti.size(); j++)
        {
            string other = mbti[j];
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                if (current[k] != other[k])
                {
                    cnt++;
                }
            }
            if (distance.find(current) == distance.end())
            {
                distance[current] = map<string, int>();
                distance[current][other] = cnt;
            }
            else
            {
                distance[current][other] = cnt;
            }
        }
    }
    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        vector<string> students;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            students.push_back(s);
        }
        int smallest = 100000000;
        if (students.size() >= 33)
        {
            smallest = 0;
        }
        else
        {
            for (int i = 0; i < students.size(); i++)
            {
                for (int j = i + 1; j < students.size(); j++)
                {
                    for (int k = j + 1; k < students.size(); k++)
                    {
                        int a = distance[students[i]][students[j]];
                        int b = distance[students[j]][students[k]];
                        int c = distance[students[k]][students[i]];
                        int sum = a + b + c;
                        if (sum < smallest)
                        {
                            smallest = sum;
                        }
                    }
                }
            }
        }
        cout << smallest << endl;
    }
}