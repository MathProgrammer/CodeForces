#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int target_no_of_1s;
    scanf("%d", &target_no_of_1s);

    const int MAX = 1e6 + 3;
    char S[MAX];
    scanf("%s", S);

    vector <int> sum(MAX, 0);
    sum[0] = (S[0] == '1');
    for(int i = 1; S[i] != '\0'; i++)
        sum[i] = sum[i - 1] + (S[i] == '1');

    vector <int> sum_frequency(MAX, 0);
    sum_frequency[0] = 1; //Empty string

    long long no_of_good_substrings = 0;
    for(int i = 0; S[i] != '\0'; i++)
    {
        if(sum[i] >= target_no_of_1s)
            no_of_good_substrings += (sum_frequency[sum[i] - target_no_of_1s]);

        sum_frequency[sum[i]]++;
    }

    printf("%I64d\n", no_of_good_substrings);
    return 0;
}
