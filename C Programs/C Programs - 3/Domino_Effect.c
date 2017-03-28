#include <stdio.h>
#include <stdlib.h>

int find_no_of_standing_dominos(char *);
int main()
{
    int no_of_dominos, no_of_standing_dominos;
    scanf("%d",&no_of_dominos);

    char *domino_line = malloc((no_of_dominos + 1)*sizeof(char));
    scanf("%s",domino_line);

    no_of_standing_dominos = find_no_of_standing_dominos(domino_line);
    printf("%d\n",no_of_standing_dominos);
    free(domino_line);
    return 0;
}

/*
1. As we go through the domino line from the first domino, every '.' is counted as a standing domino.
2. If the character in front of a '.' is L, then every domino before it falls. So, the number of standing dominos is reset to 0.

3. If we find a 'R' at D(i), then we keep going ahead till we find either a 'L' at D(j) or the end of the string at j.
			If there are an odd number of dominos in between position i and j, then one domino stands.
			If there are an even number of dominos in between position i and j, they all fall.

			So, if {D(j) = 'R' and (j-i-1) is odd}, no_of_dominos++.
			{-1 because we are counting the number of dominos in between i and j, exclusive. j not counted}

			i is then updated to j,

4.If we find a 'L', at D(i) then we keep going ahead till we find either a 'R' at D(j) or the end of the string at position j.
			In either case, all the dominos from i+1 to j-1 stand.
			no_of_standing_dominos = no_of_standing_dominos + (j - i - 1) {-1 because the j-th domino doesn't stand}

			i is then updated to j.

After the dots at the beginning i.e. after the first time D(i) is an alphabet,
 i will always be either an alphabet or the end of the string.
This is why we can afford to increment the no of standing dominos every time D(i) is a '.' */

int find_no_of_standing_dominos(char *domino_line)
{
    int no_of_standing_dominos = 0, i, j;

    for(i = 0; *(domino_line + i) != '\0';)
    {
        if(*(domino_line + i) == '.')//These are only for the dots at the beginning
        {
            no_of_standing_dominos++;//These dominos occur at the front.
            i++;
            if(*(domino_line + i) == 'L')
            {
                no_of_standing_dominos = 0;
            }
            continue;
        }
        else if(*(domino_line + i) == 'R')
        {
            //Searching for the next 'L' or the end of the string
            for(j = i + 1; (*(domino_line + j) != '\0') && (*(domino_line + j) != 'L'); j++);

            if( (*(domino_line + j) == 'L') && ((j-i - 1)%2 == 1) ) //-1 because the j-th domino isn't counted. No of dominos in between i and j, exclusive
            {
                no_of_standing_dominos++; // Only one domino stands if the number of dominos in between them is odd
            }
            i = j; //i continues where j ends
        }
        else if(*(domino_line + i) == 'L')
        {
            for(j = i + 1; (*(domino_line + j) != '\0') && (*(domino_line + j) != 'R'); j++);

            no_of_standing_dominos = no_of_standing_dominos + (j - i - 1);//After a left pushed domino, all the dominos in between i and j stand
            i = j;
        }
    }

    return no_of_standing_dominos;
}
