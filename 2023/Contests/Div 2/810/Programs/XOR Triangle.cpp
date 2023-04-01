#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353, MAX_N = 2e5 + 5, MAX_MASK = 7, NO_OF_TRIANGLE_SIDES = 3;
long long no_of_triplets[MAX_N][MAX_MASK + 1][MAX_MASK + 1];
int limit[NO_OF_TRIANGLE_SIDES], next_bit[NO_OF_TRIANGLE_SIDES], triangle_sides[NO_OF_TRIANGLE_SIDES];

int is_bit_set(int n, int bit)
{
    return ( (n&(1 << bit)) != 0 );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    no_of_triplets[0][MAX_MASK][0] = 1;
    for(int i = 0; i < S.size(); i++)
    {
        int prefix = i - 1;
        for(int prefix_match = 0; prefix_match <= MAX_MASK; prefix_match++)
        {
            for(int condition_met = 0; condition_met <= MAX_MASK; condition_met++)
            {
                for(int bit = 0; bit < NO_OF_TRIANGLE_SIDES; bit++)
                {
                    limit[bit] = (is_bit_set(prefix_match, bit) ? S[i] : '1') - '0';
                }

                for(next_bit[0] = 0; next_bit[0] <= limit[0]; next_bit[0]++)
                {
                    for(next_bit[1] = 0; next_bit[1] <= limit[1]; next_bit[1]++)
                    {
                        for(next_bit[2] = 0; next_bit[2] <= limit[2]; next_bit[2]++)
                        {

                            for(int bit = 0; bit < NO_OF_TRIANGLE_SIDES; bit++)
                            {
                                triangle_sides[bit] = next_bit[bit]^next_bit[(bit + 1)%NO_OF_TRIANGLE_SIDES];
                            }

                            int next_prefix_match = 0;
                            for(int bit = 0; bit < NO_OF_TRIANGLE_SIDES; bit++)
                            {
                                if(is_bit_set(prefix_match, bit) && next_bit[bit] == S[i] - '0')
                                {
                                    next_prefix_match |= (1 << bit);
                                }
                            }

                            int next_condition_met = 0;
                            for(int bit = 0; bit < NO_OF_TRIANGLE_SIDES; bit++)
                            {
                                int condition_here = (triangle_sides[bit]&triangle_sides[(bit + 1)%NO_OF_TRIANGLE_SIDES] != 0);
                                if(is_bit_set(condition_met, bit) || condition_here)
                                {
                                    next_condition_met |= (1 << bit);
                                }
                            }

                            no_of_triplets[i + 1][next_prefix_match][next_condition_met] += no_of_triplets[i][prefix_match][condition_met];
                            no_of_triplets[i + 1][next_prefix_match][next_condition_met] %= MOD;

                            /*cout << "F(" << i + 1 << "," << next_prefix_match << "," << next_condition_met << ") = "
                            << no_of_triplets[i + 1][next_prefix_match][next_condition_met] << " added "
                            << "F(" << i << "," << prefix_match << "," << condition_met << ") = "
                            << no_of_triplets[i][prefix_match][condition_met] << " Current "
                            << next_bit[0] << " " << next_bit[1] << " " << next_bit[2] << "\n";*/
                        }
                    }
                }
            }
        }
    }

    long long answer = 0;
    for(int prefix_match = 0, all_conditions_met = MAX_MASK; prefix_match <= MAX_MASK; prefix_match++)
    {
        answer += no_of_triplets[S.size()][prefix_match][all_conditions_met];
        answer %= MOD;
    }

    cout << answer << "\n";
    return 0;
}
