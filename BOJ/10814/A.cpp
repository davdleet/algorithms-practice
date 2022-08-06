#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:
    int age;
    string name;
    int order;
    Person(int a, string n, int o)
    {
        age = a;
        name = n;
        order = o;
    }
};

vector<Person> arr(100001, Person(0, "", 0));

bool mysort(Person a, Person b)
{
    if (a.age < b.age)
    {
        return true;
    }
    else if (a.age == b.age)
    {
        return a.order < b.order;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        arr[i].age = age;
        arr[i].name = name;
        arr[i].order = i;
    }
    sort(arr.begin(), arr.begin() + N, mysort);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i].age << " " << arr[i].name << "\n";
    }
}