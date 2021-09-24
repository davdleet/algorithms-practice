#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<int> arr;
    bool odd = false;
    int solutions = 0;
    if (N % 2 != 0)
    {
        odd = true;
        int temp = N - 1;
        int half = temp / 2;
        cout << half << " + " << half + 1 << " = " << half * 2 + 1 << endl;
        solutions++;
    }
    for (int i = N - 1; i > 1; i--)
    {
        double n = N;
        if (N % i == 0)
        {
            arr.push_back(i);
        }
        else if (fmod(n / i, 0.5) == 0)
        {
            arr.push_back(i);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (N % arr[i] != 0)
        {
            double n = N;
            double middle_temp = n / arr[i];
            if (middle_temp * 2 == N)
            {
                continue;
            }
            int middle = middle_temp;
            int count = arr[i];
            int first_half = count / 2 - 1;
            int second_half = count / 2;
            vector<int> elements;
            int start = middle - first_half;
            if (start <= 0)
            {
                continue;
            }
            int result = middle;
            for (int j = 0; j < first_half; j++)
            {
                result += start;
                elements.push_back(start);
                start++;
            }
            elements.push_back(middle);
            start = middle + 1;
            for (int j = 0; j < second_half; j++)
            {
                result += start;
                elements.push_back(start);
                start++;
            }
            if (result == N)
            {
                for (int j = 0; j < elements.size(); j++)
                {
                    if (j != elements.size() - 1)
                    {
                        cout << elements[j] << " + ";
                    }
                    else
                    {
                        cout << elements[j] << " = " << N << endl;
                        solutions++;
                    }
                }
            }
        }
        else
        {
            int middle = arr[i];
            int count = (N / middle) - 1;
            count = count / 2;
            int result = 0;
            int first = middle - count;
            if (first <= 0)
            {
                continue;
            }
            int second = middle + 1;
            vector<int> elements;
            for (int j = 0; j < count; j++)
            {
                elements.push_back(first);
                result += first;
                first++;
            }
            result += middle;
            elements.push_back(middle);
            for (int j = 0; j < count; j++)
            {
                if (j != count - 1)
                {
                    elements.push_back(second);
                    result += second;
                    second++;
                }
                else
                {
                    elements.push_back(second);
                    result += second;
                    second++;
                }
            }
            if (result == N)
            {
                solutions++;
                for (int j = 0; j < elements.size(); j++)
                {
                    if (j != elements.size() - 1)
                    {
                        cout << elements[j] << " + ";
                    }
                    else
                    {
                        cout << elements[j] << " = " << N << endl;
                    }
                }
            }
        }
    }
    cout << solutions;
}