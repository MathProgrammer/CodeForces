#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_letters;
    scanf("%d", &no_of_letters);

    int previous_letter_status = 0, no_of_unread_letters = 0, no_of_unread_segments = 0;
    for(int i = 1; i <= no_of_letters; i++)
    {
        int unread;
        scanf("%d", &unread);

        no_of_unread_letters += (unread == 1);

        if(previous_letter_status == 0 && unread == 1)
            no_of_unread_segments++;

        previous_letter_status = unread;
    }

    int no_of_operations = no_of_unread_letters + max(no_of_unread_segments - 1, 0); //Incase there are no unread segments, it should be 0
    printf("%d\n", no_of_operations);

    return 0;
}
