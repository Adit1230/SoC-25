#include <stdio.h>

void calc_depth(int* managers, int* depth, int i)
{
	if (managers[i] == -1)
	{
		depth[i] = 1;
		return;
	}

	if (! depth[managers[i]])
	{
		calc_depth(managers, depth, managers[i]);
	}

	depth[i] = depth[managers[i]] + 1;
	return;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	++n;

	int managers[n], depth[n], max_depth = 0;

	for (i = 1; i < n; ++i)
	{
		scanf("%d", managers+i);
		depth[i] = 0;
	}

	for (i = 1; i < n; ++i)
	{
		if (!depth[i])
		{
			calc_depth(managers, depth, i);
			
			if (depth[i] > max_depth)
			{
				max_depth = depth[i];
			}
		}
	}

	printf("%d\n", max_depth);

	return 0;
}
