#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define N 5
int N;

bool isSafe(int row, int col, char result[N][N])
{
    int i, j;

    // Check row on left side
    for (i = 0; i < col; i++)
    {
        if (result[row][i] == 'Q')
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (result[i][j] == 'Q')
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (result[i][j] == 'Q')
            return false;
    }

    // If no conflicts, then it's safe
    return true;
}

void solve(int col, char result[N][N], int *count)
{
    if (col == N)
    {
        (*count)++;
        if (*count == 1 || *count == 92 || *count == 1426 || *count == 724)
        {
            printf("Arrangement %d\n", *count);
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    printf("%c ", result[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    else
    {
        for (int row = 0; row < N; row++)
        {
            if (isSafe(row, col, result))
            {
                result[row][col] = 'Q';
                solve(col + 1, result, count);
                result[row][col] = '.';
            }
        }
    }
}

void solveQueens()
{
    char result[N][N];
    memset(result, '.', sizeof(result));
    int count = 0;

    solve(0, result, &count);
    printf("Arrangement Possible: %d\n", count);
}

int main()
{
    printf("Enter no. of Queens: ");
    scanf("%d",&N);
    solveQueens();
    return 0;
}
