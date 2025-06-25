#include <stdio.h>

int fact_with_n_0(int n)
{
	int x = n;

	while(n > 0)
	{
		n = n / 5;
		x -= n;
	}

	return 5 * x;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int x = fact_with_n_0(n);

	if (x <= fact_with_n_0(n-1))
	{
		printf("%d\n", 0);
	}
	else
	{
		printf("%d\n", 5);
		printf("%d %d %d %d %d\n", x, x+1, x+2, x+3, x+4);
	}


	return 0;
}
