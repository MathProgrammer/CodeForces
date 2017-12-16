#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    const int MAX_SIZE = 7;
    vector <int> no_of_bits(MAX_SIZE + 1, 0);

    int greatest_bit = 0;

    for(int i = 0; n > 0; i++)
    {
        no_of_bits[i] = n%10;
        n /= 10;

        greatest_bit = max(greatest_bit, no_of_bits[i]);
    }

    printf("%d\n", greatest_bit);

    for(int i = 1; i <= greatest_bit; i++)
    {
        int number = 0;

        for(int j = no_of_bits.size() - 1; j >= 0; j--)
        {
            number *= 10;

            if(no_of_bits[j] > 0)
                number++;

            no_of_bits[j]--;
        }
        printf("%d ", number);
    }

    return 0;
}
