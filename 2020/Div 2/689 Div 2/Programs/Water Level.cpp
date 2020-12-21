#include <iostream>
#include <vector>

using namespace std;

int in_between(long long x, long long left, long long right)
{
    return (left <= x && x <= right);
}

int main()
{
    long long left, right, initial, no_of_days, usage, refill;
    cin >> initial >> left >> right >> no_of_days >> usage >> refill;
    
    int possible = true;
    if(refill < usage)
    {
        long long reduction = usage - refill;
        
        if(initial + refill > right)
        {
            initial -= usage;
            no_of_days--;
        }
        
        if(left > initial)
        {
            possible = false;
        }
        
        long long days_used = (initial - left)/reduction;
        
        if(days_used < no_of_days)
        {
            possible = false;
        }
    }
    else if(refill == usage)
    {
        if(initial + refill > right && initial - refill < left)
        {
            possible = false;
        }
    }
    else
    {
        vector <int> reached(usage + 1, false);
        reached[initial%usage] = true;
        
        possible = in_between(initial, left, right);
        while(no_of_days > 0 && possible)
        {
            //cout << "Water = " << initial << " ";
            long long days_used = (initial - left)/usage;
            
            no_of_days -= days_used; //cout << "No of days = " << days_used << "\n";
            initial -= (days_used*usage); //cout << "After usage = " << initial << "\n";
            
            if(no_of_days <= 0)
            {   //cout << "Not enought days\n";
                possible = true;
                break;
            }
            
            initial += refill; //cout << "After refill = " << initial << "\n";
            
            if(initial > right)
            {   //cout << "Overflow\n";
                possible = false;
                break;
            }
            
            if(reached[initial%usage])
            {   //cout << "Already reached\n";
                possible = true;
                break;
            }
            
            
            reached[initial%usage] = true;
        }
    }
    
    cout << (possible ? "Yes" : "No") << "\n";
    
    return 0;
}
