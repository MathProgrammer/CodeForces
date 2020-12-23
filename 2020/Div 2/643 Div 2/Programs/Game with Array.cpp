#include <iostream>

using namespace std;

int main()
{
    int no_of_elements, sum;
    cin >> no_of_elements >> sum;
    
    if(sum >= 2*no_of_elements)
    {
        cout << "YES\n";
        for(int i = 1; i <= no_of_elements; i++)
        {
            cout << (i < no_of_elements ? 2 : sum - 2*(no_of_elements - 1)) << " ";
        }
        cout << "\n";
        
        cout << "1\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}
