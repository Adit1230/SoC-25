#include <stdio.h>
#include <stdlib.h>

int n, n1, mod = 1e9 + 7;
int** grid;

void find_paths(int row, int col)
{
	if (grid[row][col] >= 0)
	{
		return;
	}
	else
	{
		if (row >= n-1)
		{
			find_paths(row, col + 1);
			grid[row][col] = grid[row][col+1];
		}
		else if (col >= n-1)
		{
			find_paths(row + 1, col);
			grid[row][col] = grid[row+1][col];
		}
		else
		{
			find_paths(row + 1, col);
			find_paths(row, col + 1);
			grid[row][col] = ( ((long long int) grid[row + 1][col]) + grid[row][col + 1]) % mod;
		}

		return;
	}
}

int main()
{
	scanf("%d", &n);
	n1 = n - 1;
	grid = malloc(n * sizeof(int*));

	int i, j, * row;
	char c;

	for (i = 0; i < n; ++i)
	{
		row = malloc(n * sizeof(int));
		for (j = 0; j < n; ++j)
		{
			scanf(" %c", &c);

			if (c == '.')
			{
				row[j] = -1;
			}
			else
			{
				row[j] = 0;
			}
		}
		grid[i] = row;
	}

	if (grid[n-1][n-1])
	{
		grid[n-1][n-1] = 1;
	}

	find_paths(0, 0);

	printf("%d\n", grid[0][0]);

	for (i = 0; i < n; ++i)
	{
		free(grid[i]);
	}
	free(grid);
	
	return 0;
}
