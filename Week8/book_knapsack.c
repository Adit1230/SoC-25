#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, budget, i;
	scanf("%d %d", &n, &budget);

	int price[n], pages[n];

	for (i = 0; i < n; ++i)
	{
		scanf(" %d", price + i);
	}

	for (i = 0; i < n; ++i)
	{
		scanf(" %d", pages + i);
	}

	int* dp = calloc((budget + 1), sizeof(int));

	for (int j = 0; j < n; ++j)
	{
		for (i = budget; i >= price[j]; --i)
		{
			dp[i] = max(dp[i], dp[i - price[j]] + pages[j]);
		}
	}

	printf("%d\n", dp[budget]);

	free(dp);

	return 0;
}
