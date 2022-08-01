#include <iostream>
#include <vector>
using namespace std;

vector<long long int> dis(100002, 0);
vector<long long int> price(100002, 0);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        long long int t;
        cin >> t;
        dis[i] = t;
    }

    for (int i = 0; i < N; i++)
    {
        long long int t;
        cin >> t;
        price[i] = t;
    }
    int city = 0;
    long long int spent = 0;

    while (city < N - 1)
    {
        long long int current_price = price[city];
        long long int next_purchase;
        int city_idx = city + 1;
        // find the index of the next city to buy gas
        while (current_price < price[city_idx])
        {
            if (city_idx == N - 1)
            {
                break;
            }
            city_idx++;
        }
        next_purchase = city_idx;
        long long int distance = 0;
        // calculate distance to next city
        for (int i = city; i < next_purchase; i++)
        {
            distance += dis[i];
        }
        spent = spent + current_price * distance;
        city = next_purchase;
    }
    cout << spent;
}