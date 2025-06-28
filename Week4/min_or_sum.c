#include <stdio.h>

int main()
{
	int n, n_nums, or, x;

	for (scanf("%d", &n); n > 0; --n)
	{
		or = 0;

		for (scanf("%d", &n_nums); n_nums > 0; --n_nums)
		{
			scanf("%d", &x);
			or |= x;
		}

		printf("%d\n", or);
	}

	return 0;
}
