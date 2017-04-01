#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void read(int *, unsigned int);
unsigned int find_no_of_groups(int *, unsigned int);
unsigned int find_depth_of_employee(int, int *);
void find_depths_of_all_employees(int *, int *, unsigned int);

int main()
{
    unsigned int no_of_people, no_of_groups;

    scanf("%u",&no_of_people);

    int *immediate_manager = malloc(no_of_people*sizeof(int));
    int *depth_of_employee = malloc(no_of_people*sizeof(int));

    read(immediate_manager, no_of_people);
    find_depths_of_all_employees(depth_of_employee, immediate_manager, no_of_people);
    no_of_groups = find_no_of_groups(depth_of_employee, no_of_people);

    printf("%u\n",no_of_groups);

    free(depth_of_employee);
    free(immediate_manager);
    return 0;
}

void read(int *immediate_manager, unsigned int no_of_people)
{
    unsigned int i;

    for(i = 0; i < no_of_people; i++)
    {
        scanf("%d",(immediate_manager + i));
    }
}

/*First assign a depth to every node. The rule for depth is -
1. The root node has a depth of 0.
2. For every other node, Depth[i] = 1 + Depth[Immediate_manager(i)]*/

unsigned int find_depth_of_employee(int current_person, int *immediate_manager)
{
    int next_immediate_manager;

    if(*(immediate_manager + current_person) == -1)
    {
        return 0;
    }
    else
    {
        next_immediate_manager = *(immediate_manager + current_person) - 1; //-1 because the input counts from 1 and we count from 0 in the array
        return 1 + find_depth_of_employee(next_immediate_manager, immediate_manager);
    }
}

void find_depths_of_all_employees(int *depth_of_employee, int *immediate_manager, unsigned int no_of_people)
{
    int i;

    for(i = 0; i < no_of_people; i++)
    {
        *(depth_of_employee + i) = find_depth_of_employee(i, immediate_manager);
    }
}

/*
Here is a simple strategy that achieves the following -
1. Assign a depth to every node.
2. Place all nodes of the same depth in the same set.

We have to prove this arrangement ensure two nodes which share an edge aren't in the same set and that this happens in the minimum number of sets.

The first part is obvious. This arrangements ensures that a given set only has elements of the same depth. No two nodes (either from the same or different tree)
share an edge.

To prove it's minimum, let us assume that such an arrangement exists with the number of sets l, where l < max{depth}
Consider the tree with the nodes of maximum depth. By the pigeonhole principle there will exist one set which has nodes of this tree of two different depths.
But, They can't belong to the same tree because it would violate the condition of the partition.
This contradicts our assumption that an arrangement exists with less than max{depth} sets.

The arrangements described takes max{depth} number of nodes. So, it is the minimum number.
*/

unsigned int find_no_of_groups(int *depth_of_employee, unsigned int no_of_people)
{
    short already_counted;
    int i, j, distinct_depth_count = 0;

    int *distinct_depth = malloc(no_of_people*sizeof(int));

    for(i = 0; i < no_of_people; i++)
    {
        already_counted = false; //For the i=th element,
        for(j = 0; j < distinct_depth_count ; j++)
        {
            if(*(depth_of_employee + i) == *(distinct_depth + j) )
            {
                already_counted = true;
                break;
            }
        }

        if(already_counted == false)
        {
            *(distinct_depth + distinct_depth_count) = *(depth_of_employee + i);
            distinct_depth_count++;
        }
    }

    free(distinct_depth);
    return distinct_depth_count ; //The number of distinct depths is the answer
}
