#include <iostream>
#include <vector>

using namespace std;

void display(vector <long long> &A)
{
    cout << A.size() << "\n";
    
    for(int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    long long a, b;
    cin >> a >> b;
    
    long long left = 0, right = 1e5;
    while(right - left > 1)
    {
        long long mid = (right + left)/2;
        
        if(mid*(mid + 1) <= (a + b)*2)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    
    vector <long long> day_a, day_b;
    long long problems = left;
    for(long long i = problems; i >= 1; i--)
    {
        if(a >= i)
        {
            day_a.push_back(i);
            a -= i;
        }
        else
        {
            for(; i >= 1; i--)
            {
                if(i == a)
                {
                    day_a.push_back(i);
                    a -= i;
                }
                else
                {
                    day_b.push_back(i);
                    b -= i;
                }
            }
        }
    }
    
    display(day_a);
    display(day_b);
    
    return 0;
}
