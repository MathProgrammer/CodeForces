#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string A;
    cin >> A;

    int length = A.size();

    int is_palindrome[length + 1][length + 1] = {{false}};

    vector <int> palindrome_starts(length + 1, 0);
    vector <int> palindrome_ends(length + 1, 0);

    for(int i = 0; i < length; i++)
    {
        is_palindrome[i][i] = true;
        palindrome_starts[i] = palindrome_ends[i] = 1;
    }

    for(int substring_length = 2; substring_length < length; substring_length++)
    {

        for(int start = 0, end = start + substring_length - 1; end < length; start++, end++)
        {

            if(A[start] == A[end] && (substring_length == 2 || is_palindrome[start + 1][end - 1]))
            {
                is_palindrome[start][end] = true;
                palindrome_starts[start]++;
                palindrome_ends[end]++;
            }
        }
    }

    vector <int> palindromes_from(length + 1, 0);
    for(int i = length - 1; i >= 0; i--)
        palindromes_from[i] = palindromes_from[i + 1] + palindrome_starts[i];

    long long palindromic_pairs = 0;

    for(int i = 0; i < length; i++)
        palindromic_pairs += palindrome_ends[i]*1LL*palindromes_from[i + 1];

    printf("%I64d\n", palindromic_pairs);

    return 0;
}
