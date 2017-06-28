int main()
{
    const int INFINITY = 1e9 + 1;
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    precompute_prime_distance();

    vector <vector <int> > matrix(no_of_rows, vector<int> (no_of_columns) );

    for(int row = 0; row < no_of_rows; row++)
    {
        for(int column = 0; column < no_of_columns; column++)
        {
            int element;
            scanf("%d", &element);

            matrix[row][column] = prime_distance[element];
        }
    }

    int min_row_sum = INFINITY;
    for(int row = 0; row < no_of_rows; row++)
    {
        int row_sum = 0;
        for(int column = 0; column < no_of_columns; column++)
        {
            row_sum += matrix[row][column];
        }
        min_row_sum = min(min_row_sum, row_sum);
    }

    int min_column_sum = INFINITY;
    for(int column = 0; column < no_of_columns; column++)
    {
        int column_sum = 0;
        for(int row = 0; row < no_of_rows; row++)
        {
            column_sum += matrix[row][column];
        }
        min_column_sum = min(min_column_sum, column_sum);
    }

    printf("%d\n",min(min_row_sum, min_column_sum));
    return 0;
}
