#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    const int MOD = 1e9 + 7;
    long long total_sequences = 1, current_block_of_a = 0;
    for(int i = 0; i <= S.size(); i++)
    {
        if(S[i] == 'a')
        {
            current_block_of_a++;
        }
        else if(i == S.size() || S[i] == 'b')
        {
            total_sequences = (total_sequences*(current_block_of_a + 1))%MOD;

            current_block_of_a = 0;
        }
    }

    total_sequences = (total_sequences + MOD - 1)%MOD;
    cout << total_sequences;

    return 0;
}
