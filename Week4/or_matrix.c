#include <stdio.h>

int main()
{
	int n_testcases, n, row[1000], ans[1000], i, j;
	char valid;
	scanf("%d", &n_testcases);

	for (; n_testcases > 0; --n_testcases)
	{
		scanf("%d", &n);
		valid = 1;

		if (n == 1)
		{
			scanf("%*d");
			printf("yes\n1\n");
			continue;
		}

		for (i = 0; i < n; ++i)
		{
			ans[i] = ~0;
			for (j = 0; j < n; ++j)
			{
				scanf("%d", row + j);
				if (i != j)
					ans[i] &= row[j];
			}

			for (j = 0; j < i; ++j)
			{
				if ((ans[i] | ans[j]) != row[j])
				{
					valid = 0;
					break;
				}
			}

			if (!valid)
			{
				i = n * (n - i - 1);
				for(j = 0; j < i; ++j)
				{
					scanf("%*d");
				}
				break;
			}
		}

		if (valid)
		{
			printf("yes\n");
			for (i = 0; i < n; ++i)
			{
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		else
		{
			printf("no\n"); 
		}
	}

	return 0;
}
