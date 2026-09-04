#include <stdio.h>

int main()
{
    int row_size, col_size;
    printf("Enter row size: ");
    scanf("%d", &row_size);
    printf("Enter column size: ");
    scanf("%d", &col_size);
    int number_array[row_size][col_size];

    printf("Enter the values: ");
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            scanf("%d", &number_array[i][j]);
            if (number_array[i][j] != 0)
            {
                printf("%d %d %d", i, j, number_array[i][j]);
            }
        }
    }
}