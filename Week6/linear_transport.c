#include <stdio.h>

int main()
{
	int n, t, i, next;
	scanf("%d %d", &n, &t);

	for (i = 1; i < t; ++i)
	{
		for (scanf("%d", &next); next > 1; --next)
		{
			scanf("%*d");
			++i;
		}
	}

	for (; n > i; --n)
	{
		scanf("%*d");
	}

	if (i == t)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
