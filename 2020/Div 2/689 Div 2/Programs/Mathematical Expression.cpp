#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;
int last_plus[MAX_N], max_answer[MAX_N];

void solve(int left, int right, vector <char> &S, vector <int> &A)
{
    while(left <= right && A[left] == 1)
    {
        S[left] = '+';
        left++;
    }
    
    if(right <= left)
    {
        return;
    }
    
    while(right >= left && A[right] == 1)
    {
        S[right - 1] = '+';
        right--;
    }
    
    const int MAX_NON_1 = 20;
    int non_1 = 0;
    for(int i = left; i <= right; i++)
    {
        non_1 += (A[i] != 1);
    }
    
    if(non_1 >= MAX_NON_1)
    {
        for(int i = left; i < right; i++)
        {
            S[i] = '*';
        }
        
        return;
    }
    
    for(int i = left; i <= right; i++)
    {
        last_plus[i] = 0;
        max_answer[i] = 0;
    }
    
    for(int i = left; i <= right; i++)
    {
        if(A[i] == 1)
        {
            max_answer[i] = max_answer[i - 1] + 1;
            last_plus[i] = i - 1;
            continue;
        }
        
        long long product_here = 1;
        for(int j = i; j >= left; j--)
        {
            product_here *= A[j];
            
            if(product_here + max_answer[j - 1] > max_answer[i])
            {
                max_answer[i] = max_answer[j - 1] + product_here;
                last_plus[i] = j - 1;
                
                //cout << "Max " << j << " = " << max_answer[j] << " and last plus = " << last_plus[i] << "\n";
            }
        }
    }
    
    for(int i = right; i >= left; i = last_plus[i])
    {
        for(int j = i - 1; j > last_plus[i]; j--)
        {
            S[j] = '*';
        }
        
        S[last_plus[i]] = '+';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 5, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    string S;
    cin >> S;
    
    sort(S.begin(), S.end());
    
    if(S.size() == 1)
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            cout << A[i] << (i < no_of_elements ? S : "\n");
        }
        
        return 0;
    }
    
    if(S == "+-")
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            cout << A[i] << (i < no_of_elements ? "+" : "\n");
        }
        
        return 0;
    }
    
    if(S == "*-")
    {
        for(int i = 1; i <= no_of_elements; i++)
        {
            cout << A[i];
            if(i < no_of_elements)
            {
                cout << (A[i + 1] == 0 ? "-" : "*");
            }
        }
        
        cout << "\n";
        
        return 0;
    }
    
    vector <char> signs(no_of_elements + 5, '?');
    
    //Invariant that A[i] = 0 always
    for(int i = 0, j = 1; i < no_of_elements; i = j)
    {
        for(j = i + 1; j <= no_of_elements && A[j] != 0; )
        {
            j++;
        }
        
        
        //cout << "Solve [" << i + 1 << "," << j - 1 << "]\n";
        solve(i + 1, j - 1, signs, A);
        signs[i - 1] = signs[i] = signs[j - 1] = signs[j] = '+';
        
        /*for(int i = 1; i <= no_of_elements; i++)
        {
            cout << A[i] << (i < no_of_elements ? signs[i] : '\n');
        }*/
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << (i < no_of_elements ? signs[i] : '\n');
    }
    return 0;
}
