#include <stdio.h>

#define MAX_NO_DIGITS 11
unsigned int get_index(char[]);
int main()
{
    char lucky_number[MAX_NO_DIGITS];
    unsigned int index;

    scanf("%s",lucky_number);

    index = get_index(lucky_number);

    printf("%u\n",index);
    return 0;
}

unsigned int get_index(char lucky_number[])
{
    short i;
    unsigned int index = 1; //index can be atmost 2^{11} - 1 - A binary string with 11 ones. Int is sufficient

    /*Construct a binary string in correspondence to the lucky number,
    b[0] = 0,
    b[i + 1] = 0, if d[i] = 4 and
    b[i + 1] = 1, if d[i] = 7
    4 corresponds with 01, 7 with 11, 44 with 001, 47 with 011 and so on.
    Where b[i] is the i-th letter of the binary string, and d[i] is the i-th letter of the decimal string.
    The binary string must be read from right to left.
    The binary number we get is (reversed) always one more than the lexicographic number of the digit we have gotten since the first string is 2 and not 1.
    So, we subtract 1 at the end, after constructing a binary number from the given decimal string.
    We read the decimal string from right to left and then keep shifting each character to the left so that the rightmost character is at the left.
    This way we already get the reversed binary string, as required. */
    for(i = 0; lucky_number[i] != '\0'; i++)
    {
        if(lucky_number[i] == '4')
        {
            index = (index << 1);
        }
        else if(lucky_number[i] == '7')
        {
            index = (index << 1) + 1;
        }
    }

    index = index - 1;
    return index;
}
