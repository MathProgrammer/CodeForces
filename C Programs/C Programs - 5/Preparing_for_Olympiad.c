#include <stdio.h>
#include <stdlib.h>
void read(long *, int);
long min(long, long);
long max(long, long);
long count_no_of_problem_sets(long *, int,long, long,long);

int main()
{
    int no_of_problems;
    long min_difficulty, max_difficulty,least_difficulty_range, no_of_problem_sets;
    scanf("%d %ld %ld %ld",&no_of_problems, &min_difficulty, &max_difficulty, &least_difficulty_range);

    long *problem_difficulty = malloc(no_of_problems*sizeof(long));
    read(problem_difficulty, no_of_problems);

    no_of_problem_sets = count_no_of_problem_sets(problem_difficulty, no_of_problems, min_difficulty, max_difficulty, least_difficulty_range);
    printf("%ld\n",no_of_problem_sets);

    free(problem_difficulty);
    return 0;
}

long count_no_of_problem_sets(long *problem_difficulty, int no_of_problems,long min_difficulty, long max_difficulty,long least_difficulty_range)
{
    /*We construct a binary string in bijection to the problems chosen. If the i-th bit is 1, then it means that the i-th problem is chosen
    If i-th bit is 0, then it isn't chosen. This bitmask is n digits long. We know n is always less than 15
    The binary string is helpful in visiting every set that can be chosen from these n elements.*/
    int current_problem_no, bitmask, total_no_of_problem_sets = 1 << no_of_problems; //No of binary strings of length n is 2^n. 1 right shifted n times is 2^n
    long total_legitimate_arrangements = 0, current_min_difficulty, current_max_difficulty, problems_in_set;
    long total_difficulty;

    //Now, we iterate through all the bitmasks
    for(bitmask = 1; bitmask < total_no_of_problem_sets; bitmask++)
    {
        total_difficulty = 0;
        problems_in_set = 0;
        /*The values of minimum and maximum are so set that the first problem selected becomes both min and max and from there it's just the
        standard way of finding min and max in an array.
        The min and max can't be set to the first element like usual because the first element may not be part of the chosen set.*/
        current_min_difficulty = 1e6 + 1;
        current_max_difficulty = -1;

        for(current_problem_no = 0; current_problem_no < no_of_problems; current_problem_no++)
        {
            //The number 2^j corresponds with only the j-th problem chosen. We AND this with the current bitmask. If it's non-zero, then j-problem
            //is chosen in this arrangement
            if(bitmask & (1 << current_problem_no))
            {
                current_min_difficulty = min(current_min_difficulty, *(problem_difficulty + current_problem_no));
                current_max_difficulty = max(current_max_difficulty, *(problem_difficulty + current_problem_no));
                total_difficulty = total_difficulty + *(problem_difficulty + current_problem_no);
                problems_in_set++;
            }
        }

        if( (problems_in_set >= 2) && (total_difficulty >= min_difficulty) && (total_difficulty <= max_difficulty) &&
           (current_max_difficulty-current_min_difficulty >=least_difficulty_range) )
        {
            total_legitimate_arrangements++;
        }
    }

    return total_legitimate_arrangements;
}

void read(long *problem_difficulty, int no_of_problems)
{
    int i;
    for(i = 0; i < no_of_problems; i++)
    {
        scanf("%ld",(problem_difficulty + i));
    }
}

long min(long a, long b)
{
    if(a < b)
        return a;
    else
        return b;
}
long max(long a, long b)
{
    if(a > b)
        return a;
    else
        return b;
}
