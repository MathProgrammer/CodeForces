#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define all(v) (v).begin(), (v).end()

long long gcd(long long a, long long b)
{
    if(min(a, b) == 0)
        return max(a, b);
    
    return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int no_of_elements_a, no_of_elements_b;
    cin >> no_of_elements_a >> no_of_elements_b;
    
    vector <long long> A(no_of_elements_a + 1), B(no_of_elements_b + 1);
    for(int i = 1; i <= no_of_elements_a; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 1; i <= no_of_elements_b; i++)
    {
        cin >> B[i];
    }
    
    sort(all(A));
    
    vector <long long> difference(no_of_elements_a);
    for(int i = 1; i < no_of_elements_a; i++)
    {
        difference[i] = A[i + 1] - A[i];
    }
    
    long long array_gcd = 0;
    for(int i = 2; i < no_of_elements_a; i++)
    {
        array_gcd = gcd(array_gcd, difference[i]);
    }
    
    vector <long long> answer(no_of_elements_b + 1);
    for(int i = 1; i <= no_of_elements_b; i++)
    {
        answer[i] = gcd(A[1] + B[i], array_gcd);
    }
    
    for(int i = 1; i <= no_of_elements_b; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
