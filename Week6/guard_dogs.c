#include <stdio.h>

int main()
{
	int m, n, i, j;
	scanf("%d", &m);
	scanf("%d", &n);

	char field[m+2][n+2], curr, possible = 1;

	for (i = 0; i < m+2; ++i)
	{
		for (j = 0; j < n+2; ++j)
		{
			field[i][j] = 0;
		}
	}

	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf(" %c", &curr);

			switch(curr)
			{
				case '.':
					field[i][j] = 'D';
					break;

				case 'S':
					if (field[i][j] == 'U')
					{
						possible = 0;
					}
					else
					{
						field[i][j] = 'S';
					}
					break;

				case 'W':
					if (field[i-1][j] == 'S' || field[i][j-1] == 'S')
					{
						possible = 0;
					}
					else
					{
						field[i][j] = 'W';
						field[i+1][j] = 'U';
						field[i][j+1] = 'U';
					}
					break;

			}

			if (!possible)
			{
				break;
			}

		}

		if (!possible)
		{
			break;
		}
	
	}

	if (!possible)
	{
		for(int r = ((m - i) * n) + (n - j); r > 0; --r)
		{
			scanf(" %*c");
		}

		printf("No\n"); 
	}
	else
	{
		printf("Yes\n");
		
		for (i = 1; i <= m; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				printf("%c", field[i][j]);
			}
			printf("\n");
		}
	}



	return 0;
}
