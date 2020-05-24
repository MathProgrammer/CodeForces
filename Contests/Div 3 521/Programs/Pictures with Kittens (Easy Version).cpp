#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, segment, total;
    cin >> no_of_elements >> segment >> total;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int oo = 1e9;
    vector <vector <long long> > max_till(no_of_elements + 1, vector <long long> (total + 1, -oo));
    max_till[0][total] = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int remaining = total - 1; remaining >= 0; remaining--)
        {
            if(remaining == total)
            {
                max_till[i][remaining] = 0;
                continue;
            }
            
            for(int last = i - 1; last >= 0 && last >= i - segment; last--)
            {
                if(max_till[last][remaining + 1] != -oo)
                {
                    max_till[i][remaining] = max(max_till[i][remaining], A[i] + max_till[last][remaining + 1]);
                }
            }
            
            //cout << "F(" << i << "," << remaining << ") = " << max_till[i][remaining] << "\n";
        }
    }
    
    long long answer = -oo;
    for(int i = no_of_elements - segment + 1; i <= no_of_elements; i++)
    {
        answer = max(answer, max_till[i][0]);
    }
    
    cout << (answer == -oo ? -1 : answer) << "\n";
    return 0;
}
