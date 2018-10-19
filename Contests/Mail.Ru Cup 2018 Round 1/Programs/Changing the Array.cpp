#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

LL choose_2(LL n)
{
    return (n*(n - 1))/2;
}

int all_ones(int n)
{
    return ((1 << n) - 1);
}

int complement(int n, int k)
{
    return (all_ones(k) - n);
}

int main()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;

    int prefix_xor = 0;
    map <int, int> prefix_xor_frequency;
    prefix_xor_frequency[0] = 1;

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;

        int option_1 = prefix_xor^element;
        int option_2 = prefix_xor^complement(element, k);

        if(prefix_xor_frequency[option_1] < prefix_xor_frequency[option_2])
            prefix_xor = option_1;
        else
            prefix_xor = option_2;

        prefix_xor_frequency[prefix_xor]++;
    }

    LL bad_segments = 0;
    for(map <int, int> :: iterator it = prefix_xor_frequency.begin(); it != prefix_xor_frequency.end(); it++)
    {
        bad_segments += choose_2(it->second);
    }

    LL total_segments = choose_2(no_of_elements) + no_of_elements;
    LL good_segments = total_segments - bad_segments;

    cout << good_segments;
    return 0;
}
