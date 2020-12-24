#include <iostream>

using namespace std;

void solve()
{
    int length;
    string R, B;
    cin >> length >> R >> B;
    
    int red_cards = 0, blue_cards = 0;
    for(int i = 0; i < length; i++)
    {
        if(R[i] > B[i])
        {
            red_cards++;
        }
        else if(B[i] > R[i])
        {
            blue_cards++;
        }
    }
    
    if(red_cards == blue_cards)
    {
        cout << "EQUAL\n";
    }
    else
    {
        cout << (red_cards > blue_cards ? "RED\n" : "BLUE\n");
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
