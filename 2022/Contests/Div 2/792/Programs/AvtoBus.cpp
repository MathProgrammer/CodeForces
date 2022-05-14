#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long no_of_wheels;
    cin >> no_of_wheels;

    long long minimum, maximum;
    switch(no_of_wheels%4)
    {
        case 0: maximum = no_of_wheels/4;
                minimum = 2*(no_of_wheels/12) + (no_of_wheels%12 == 6 ? (no_of_wheels%12)/6 : (no_of_wheels%12)/4);
                          break;

        case 2: if(no_of_wheels == 2)
                {
                    cout << "-1\n";
                    return;
                }
                maximum = 1 + (no_of_wheels - 6)/4;
                no_of_wheels -= 6;
                minimum = 1 + 2*(no_of_wheels/12) + (no_of_wheels%12 == 6 ? (no_of_wheels%12)/6 : (no_of_wheels%12)/4);
                break;

        default: cout << "-1\n";
                 return;
    }

    cout << minimum << " " << maximum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
