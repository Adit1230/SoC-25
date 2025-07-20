#include <stdio.h>

int main()
{
	int i, n, curr, x;
	scanf("%d", &n);

	int next[n+1], ans[n+1];

	for (i = 1; i <= n; ++i)
	{
		scanf("%d", next+i);
		ans[i] = 0;
	}

	for (i = 1; i <= n; ++i)
	{
		if (ans[i])
		{
			continue;
		}

		curr = i;

		while (ans[curr] == 0)
		{
			ans[curr] = -10;
			curr = next[curr];
		}

		if (ans[curr] == -10)
		{
			while (ans[curr] == -10)
			{
				ans[curr] = curr;
				curr = next[curr];
			}
		}

		
		curr = i;
		while (ans[curr] == -10)
		{
			curr = next[curr];
		}
		x = ans[curr];
		
		curr = i;
		while (ans[curr] == -10)
		{
			ans[curr] = x;
			curr = next[curr];
		}

	}

	for (i = 1; i <= n; ++i)
	{
		printf("%d ", ans[i]);
	}

	printf("\n");

	

	return 0;
}
