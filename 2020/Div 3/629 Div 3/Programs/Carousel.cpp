#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    set <int> distinct;
    for(int i = 0; i < no_of_elements; i++)
    {
        distinct.insert(A[i]);
    }
    
    int no_of_colours = 1;
    vector <int> colour(no_of_elements + 1, 1);
    
    if(distinct.size() == 1)
    {
        no_of_colours = 1;
        for(int i = 0; i < no_of_elements; i++)
        {
            colour[i] = 1;
        }
    }
    else if(no_of_elements%2 == 0)
    {
        no_of_colours = 2;
        for(int i = 0; i < no_of_elements; i++)
        {
            colour[i] = (i%2 == 0 ? 2 : 1);
        }
    }
    else
    {
        no_of_colours = 2;
        
        int equal_point = -1;
        for(int i = 0; i < no_of_elements; i++)
        {
            if(A[i] == A[(i + 1)%no_of_elements])
            {
                equal_point = (i + 1)%no_of_elements;
                break;
            }
        }
        
        if(equal_point != -1)
        {
            for(int i = 0; i < no_of_elements; i++)
            {
                if(i < equal_point)
                {
                    colour[i] = (i%2 == 0 ? 2 : 1);
                }
                else if(i == equal_point)
                {
                    colour[i] = ((i + 1)%2 == 0 ? 2 : 1); //Same as Previous
                }
                else if(i > equal_point)
                {
                    colour[i] = (i%2 == 0 ? 1 : 2);
                }
            }
        }
        else
        {
            no_of_colours = 3;
            for(int i = 0; i < no_of_elements; i++)
            {
                colour[i] = (i%2 == 0 ? 2 : 1);
            }
            
            colour[no_of_elements - 1] = 3;
        }
    }
    
    
    cout << no_of_colours << "\n";
    for(int i = 0; i < no_of_elements; i++)
    {
        cout << colour[i] << " ";
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
