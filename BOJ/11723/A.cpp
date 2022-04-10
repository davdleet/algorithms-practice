#include <iostream>
#include <set>
using namespace std;

class MySet
{
public:
    MySet()
    {
    }
    void add(int num)
    {
        s.insert(num);
    }
    void remove(int num)
    {
        s.erase(num);
    }
    void check(int num)
    {
        auto result = s.find(num);
        if (result == s.end())
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }
    void toggle(int num)
    {
        auto result = s.find(num);
        if (result == s.end())
        {
            add(num);
        }
        else
        {
            remove(num);
        }
    }
    void all()
    {
        for (int i = 1; i <= 20; i++)
        {
            s.insert(i);
        }
    }
    void empty()
    {
        s.clear();
    }

private:
    set<int> s;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    MySet s = MySet();
    for (int i = 0; i < N; i++)
    {
        string ins;
        int num;
        cin >> ins;
        if (ins != "all" && ins != "empty")
        {
            cin >> num;
        }
        if (ins == "add")
        {
            s.add(num);
        }
        else if (ins == "remove")
        {
            s.remove(num);
        }
        else if (ins == "check")
        {
            s.check(num);
        }
        else if (ins == "toggle")
        {
            s.toggle(num);
        }
        else if (ins == "all")
        {
            s.all();
        }
        else if (ins == "empty")
        {
            s.empty();
        }
    }
}