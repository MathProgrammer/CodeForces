#include <stdio.h>

unsigned long long find_no_of_cycles(int);
void raise_matrix_power(unsigned long long[][2], int);
void multiply(unsigned long long [][2], unsigned long long [][2]);
void copy(unsigned long long [][2], unsigned long long [][2]);

const long long mod = 1e9 + 7;
int main()
{
    int no_of_moves;
    unsigned long long no_of_cyclic_paths;
    scanf("%d",&no_of_moves);
    no_of_cyclic_paths = find_no_of_cycles(no_of_moves);
    printf("%I64u\n",no_of_cyclic_paths);
    return 0;
}

unsigned long long find_no_of_cycles(int no_of_moves)
{
    unsigned long long matrix[2][2];

    if(no_of_moves == 0)
    {
        return 1;
    }
    /*
    | f^n(D)    | = | 0    3 | | f^{n-1}(D)   |
    | f^n(ABC)  | = | 1    2 | | f^{n-1}(ABC) |
    Also, f^0(D) = 1 and f^0(ABC) = 0. */
    matrix[0][0] = 0;
    matrix[0][1] = 3;
    matrix[1][0] = 1;
    matrix[1][1] = 2;
    raise_matrix_power(matrix, no_of_moves);

    return (matrix[0][0]*1 + matrix[0][1]*0);//f^n(D) = first_row(A^n) * (1, 0)
}

//Binary exponentiation
void raise_matrix_power(unsigned long long matrix[][2], int exponent)
{
    unsigned long long answer[2][2];

    /*Initialise it to identity Answer = I_2*/
    answer[0][0] = answer[1][1] = 1;
    answer[0][1] = answer[1][0] = 0;

    while(exponent > 0)
    {
        if(exponent%2 == 1)
        {
            multiply(answer, matrix);//Answer = Answer*A
        }
        multiply(matrix, matrix); //A = A*A
        exponent = exponent >> 1;
    }

    copy(matrix, answer);
}

void multiply(unsigned long long matrix_1[][2], unsigned long long matrix_2[][2])
{
    short i, j, k;
    unsigned long long product[2][2];

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            product[i][j] = 0;
            for(k = 0; k < 2; k++)
            {
                product[i][j] += matrix_1[i][k]*matrix_2[k][j];
                product[i][j] = (product[i][j]% mod);
            }
        }
    }

    copy(matrix_1, product);
}

void copy(unsigned long long matrix_1[][2], unsigned long long matrix_2[][2])
{
    short i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            matrix_1[i][j] = matrix_2[i][j];
        }
    }
}
