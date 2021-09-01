#include <iostream>

using namespace std;

int main()
{
    int first, second;
    int current = 2019;
    int gender_num;
    int birth_year;
    char gender;
    int age;
    scanf("%d-%d", &first, &second);
    gender_num = second / 1000000;

    if (gender_num == 1)
    {
        birth_year = 1900;
        gender = 'M';
    }
    else if (gender_num == 2)
    {
        birth_year = 1900;
        gender = 'W';
    }
    else if (gender_num == 3)
    {
        birth_year = 2000;
        gender = 'M';
    }
    else
    {
        birth_year = 2000;
        gender = 'W';
    }
    birth_year += (first / 10000);
    age = current - birth_year + 1;
    cout << age << " " << gender;
}