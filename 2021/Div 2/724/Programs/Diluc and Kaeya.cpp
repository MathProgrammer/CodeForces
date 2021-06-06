#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    vector <int> sum_d(length, 0), sum_k(length, 0);
    for(int i = 0; i < length; i++)
    {
        if(i > 0)
        {
            sum_d[i] = sum_d[i - 1];
            sum_k[i] = sum_k[i - 1];
        }

        switch(S[i])
        {
            case 'D': sum_d[i]++; break;
            case 'K': sum_k[i]++; break;
        }
    }

    map <pair <int, int>, int> last_occurrence;
    vector <int> answer(length, 1);
    for(int i = 0; i < length; i++)
    {
        pair <int, int> ratio_here = make_pair(sum_d[i], sum_k[i]);
        ratio_here.first /= __gcd(sum_d[i], sum_k[i]);
        ratio_here.second /= __gcd(sum_d[i], sum_k[i]);

        if(last_occurrence.find(ratio_here) != last_occurrence.end())
        {
            answer[i] = 1 + answer[last_occurrence[ratio_here]];
        }

        last_occurrence[ratio_here] = i;
    }

    for(int i = 0; i < length; i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

 
