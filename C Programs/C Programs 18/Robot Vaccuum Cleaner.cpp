#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

struct info
{
    long long no_of_s, no_of_h;
    string text;
};

int compare(const info &A, const info &B)
{
    long long no_of_new_sh_if_A_front = A.no_of_s*B.no_of_h;
    long long no_of_new_sh_if_B_front = B.no_of_s*A.no_of_h;

    if(no_of_new_sh_if_A_front > no_of_new_sh_if_B_front)
        return true;
    else
        return false;
}

int main()
{
    int no_of_strings;
    cin >> no_of_strings;

    vector <info> A(no_of_strings);
    for(int i = 0; i < no_of_strings; i++)
    {
        cin >> A[i].text;

        A[i].no_of_s = 0;
        A[i].no_of_h = 0;

        for(int j = 0; j < A[i].text.size(); j++)
        {
            A[i].no_of_s += (A[i].text[j] == 's');
            A[i].no_of_h += (A[i].text[j] == 'h');
        }
    }

    sort(all(A), compare);

    string final_text;
    for(int i = 0; i < no_of_strings; i++)
        final_text += A[i].text;

    long long no_of_s_till_here = 0, no_of_sh = 0;
    for(int i = 0; i < final_text.size(); i++)
    {
        no_of_s_till_here += (final_text[i] == 's');

        if(final_text[i] == 'h')
            no_of_sh += no_of_s_till_here;
    }

    cout << no_of_sh;
    return 0;
}
