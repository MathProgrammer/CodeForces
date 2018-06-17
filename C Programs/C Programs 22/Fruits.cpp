#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_prices, no_of_fruits;
    cin >> no_of_prices >> no_of_fruits;

    vector <int> price(no_of_prices, 0);
    for(int i = 0; i < no_of_prices; i++) cin >> price[i];

    sort(all(price));

    map <string, int> frequency;
    for(int i = 1; i <= no_of_fruits; i++)
    {
        string fruit;
        cin >> fruit;
        frequency[fruit]++;
    }

    vector <int> fruit_frequency;
    for(map <string, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
        fruit_frequency.push_back(it->second);

    sort(all(fruit_frequency));
    reverse(all(fruit_frequency));

    long long min_price = 0;
    for(int i = 0; i < fruit_frequency.size(); i++)
        min_price += price[i]*1LL*fruit_frequency[i];

    reverse(all(price));
    long long max_price = 0;
    for(int i = 0; i < fruit_frequency.size(); i++)
        max_price += price[i]*1LL*fruit_frequency[i];

    cout << min_price << " " << max_price;
    return 0;
}
