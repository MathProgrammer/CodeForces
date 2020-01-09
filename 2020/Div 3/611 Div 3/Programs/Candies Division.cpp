#include <iostream>

using namespace std;

void solve()
{
    int no_of_candies, no_of_kids;
    cin >> no_of_candies >> no_of_kids;
    
    int candies_given_to_one_kid = no_of_candies/no_of_kids;
    
    int candies_given = no_of_kids*candies_given_to_one_kid;
    no_of_candies %= no_of_kids;
    
    candies_given += min(no_of_candies, no_of_kids/2);
    
    cout << candies_given << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
