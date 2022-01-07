#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    vector<int> arr;
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) < 58 && input.at(i) > 47)
        {
            char temp_char = input.at(i);
            int temp = temp_char - '0';
            arr.push_back(temp);
        }
    }
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        double power = (arr.size() - i - 1);
        power = pow(10, power);
        result += (power * arr[i]);
    }
    cout << result << endl;
    int count = 0;
    for (int i = 1; i <= result; i++)
    {
        if (result % i == 0)
        {
            count++;
        }
    }
    cout << count;
}