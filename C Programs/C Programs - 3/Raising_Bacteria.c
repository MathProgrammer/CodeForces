#include <stdio.h>
#define MASK_1 0x5555555555555555
#define MASK_2 0x3333333333333333
#define MASK_3 0x0F0F0F0F0F0F0F0F
#define MASK_4 0x00FF00FF00FF00FF
#define MASK_5 0x0000FFFF0000FFFF
#define MASK_6 0x00000000FFFFFFFF

unsigned long long find_no_of_1_in_binary(unsigned long long);
int main()
{
    unsigned long long target_bacteria, no_of_bacteria;

    scanf("%I64u",&target_bacteria);

    no_of_bacteria = find_no_of_1_in_binary(target_bacteria);

    printf("%I64u",no_of_bacteria);
    return 0;
}

unsigned long long find_no_of_1_in_binary(unsigned long long target_bacteria)
{
    unsigned long long population_count;

    population_count = target_bacteria;
    population_count = (population_count & MASK_1) + (population_count >> 1 & MASK_1);//After this step, every pair b[i, i+1] = b[i] + b[i+1], for even i
    //After this step, every quartet b[i ..  i+3] = b[i .. i+1] + b[i+2 ... i+3] from previous step, for multiples of 4 - i
    population_count = (population_count & MASK_2) + (population_count >> 2 & MASK_2);
    //After this step, every b[i ..  i+7] = b[i .. i+3] + b[i+4 ... i+7] from previous step, for multiples of 8 - i
    population_count = (population_count & MASK_3) + (population_count >> 4 & MASK_3);
    //After this step, every b[i ..  i+15] = b[i .. i+7] + b[i+8 ... i+15] from previous step, for multiples of 16 - i
    population_count = (population_count & MASK_4) + (population_count >> 8 & MASK_4);
    //After this step, every b[i ..  i+31] = b[i .. i+15] + b[i+16 ... i+31] from previous step, for multiples of 32 - i
    population_count = (population_count & MASK_5) + (population_count >> 16 & MASK_5);
    //After this step, every b[i ..  i+63] = b[i .. i+31] + b[i+32 ... i+63] from previous step, for multiples of 64 - i
    population_count = (population_count & MASK_6) + (population_count >> 32 & MASK_6);
    //After this last step, what's left is the number of 1s in the binary representation of a number

    return population_count;
}
