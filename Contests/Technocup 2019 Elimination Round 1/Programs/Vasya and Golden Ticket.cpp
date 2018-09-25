#include <cstdio>
#include <vector>

using namespace std;

int possible_to_divide(vector <int> &A, int target_no_of_parts)
{
    int sum = 0;
    for(int i = 1; i < A.size(); i++)
        sum += A[i];

    int target_part_sum = sum/target_no_of_parts;

    int parts_that_are_made = 0;

    for(int current_part_sum = 0, i = 1; i < A.size(); i++)
    {
        current_part_sum += A[i];

        if(current_part_sum == target_part_sum)
        {
            parts_that_are_made++;

            current_part_sum = 0;
        }

        if(current_part_sum > target_part_sum)
            return false;
    }

    return (parts_that_are_made == target_no_of_parts);
}

int main()
{
    int no_of_digits;
    scanf("%d", &no_of_digits);

    vector <int> A(no_of_digits + 1);
    for(int i = 1; i <= no_of_digits; i++)
        scanf("%1d", &A[i]);

    int sum = 0;
    for(int i = 1; i <= no_of_digits; i++)
        sum += A[i];

    int division_possible = false;
    for(int i = 2; i <= no_of_digits; i++)
    {
        if(sum%i == 0)
        {
            if(possible_to_divide(A, i))
            {
                division_possible = true;
                break;
            }
        }
    }

    printf(division_possible ? "YES\n" : "NO\n");
    return 0;
}
