#include <stdio.h>

int main()
{
	int n, n_inputs, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &n_inputs);
		scanf("%d", &x);

		for ( ;n_inputs > 1; --n_inputs)
		{
			scanf("%*d");
		}

		printf("%d\n", x);
	}

	return 0;
}
