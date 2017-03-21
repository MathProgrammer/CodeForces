#include <stdio.h>
#include <string.h>

#define MAXIMUM_NUMBER_SIZE 12 //9 digit number + a sign and then two extra characters just in case

void copy_part_of_string(char[], char[], int, int);

int main()
{
    char bank_balance[MAXIMUM_NUMBER_SIZE], final_bank_balance[MAXIMUM_NUMBER_SIZE];
    short length;

    scanf("%s",bank_balance);

    //Checking if balance is positive
    if(bank_balance[0] != '-')
    {
        strcpy(final_bank_balance, bank_balance);
    }
    else //Bank balance is negative
    {
        length = strlen(bank_balance);

        //Checking which character is greater among the last and second last and deleting the smaller one.
        if(bank_balance[length - 1] < bank_balance[length - 2]) //Deleting the second last digit
        {
            copy_part_of_string(final_bank_balance, bank_balance, 0, length - 3);
            final_bank_balance[length - 2] = bank_balance[length - 1];
            final_bank_balance[length - 1] = '\0';
        }
        else //Deleting the last digit
        {
            copy_part_of_string(final_bank_balance, bank_balance, 0, length - 2);
            final_bank_balance[length - 1] = '\0';
        }

        //Incase, the bank balance becomes zero after deletion. For example, -10 becomes -0. We want it to be just zero.
        if((strlen(final_bank_balance) == 2) && (final_bank_balance[1] == '0'))
        {
            final_bank_balance[0] = '0';
            final_bank_balance[1] = '\0';
        }
    }

    printf("%s\n",final_bank_balance);
    return 0;
}

//Copies source{start_index .... end_index] to destination[0 .... end_index-start_index]
void copy_part_of_string(char destination[], char source[], int start_index, int end_index)
{
    int i;

    for(i = 0; i <= (end_index - start_index); i++)
    {
        destination[i] = source[start_index + i];
    }
}
