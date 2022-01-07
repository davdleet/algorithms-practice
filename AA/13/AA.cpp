#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int count[10] = {0};
    //freopen("input.txt", "rt", stdin);
    char input[100];
    scanf("%s", &input);
    string input_s = input;
    for (int i = 0; i < input_s.size(); i++)
    {
        char temp = input[i];
        int num = atoi(&temp);
        count[num]++;
    }
    int max = count[0];
    int max_idx = 0;
    for (int i = 1; i < 10; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            max_idx = i;
        }
        else if (count[i] == max)
        {
            if (i > max_idx)
            {
                max_idx = i;
            }
        }
    }
    cout << max_idx;
}