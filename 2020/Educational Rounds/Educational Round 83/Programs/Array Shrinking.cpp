#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int NOT_REDUCIBLE = -1, oo = 1e9;
    vector <vector <int> > final_element(no_of_elements + 1, vector <int> (no_of_elements + 1));
    for(int length = 1; length <= no_of_elements; length++)
    {
        for(int left = 1, right = left + length - 1; right <= no_of_elements; left++, right++)
        {
            final_element[left][right] = NOT_REDUCIBLE;
            
            if(length == 1)
            {
                final_element[left][right] = A[left];
                continue;
            }
            
            for(int i = left; i < right; i++)
            {
                if(final_element[left][i] != NOT_REDUCIBLE && final_element[left][i] == final_element[i + 1][right])
                {
                    final_element[left][right] = final_element[left][i] + 1;
                }
            }
        }
    }
    
    vector <int> minimum_parts(no_of_elements + 1, oo);
    minimum_parts[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(final_element[j][i] == NOT_REDUCIBLE)
            {
                continue;
            }
            
            minimum_parts[i] = min(minimum_parts[i], minimum_parts[j - 1] + 1);
        }
    }
    
    cout << minimum_parts[no_of_elements] << "\n";
    return 0;
}
