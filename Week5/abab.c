#include <stdio.h>

int main()
{
	long long int a, b, c;

	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);

	if (a == b)
	{
		printf("%lld\n", (a + c) << 1);
	}
	else if (a < b)
	{
		printf("%lld\n", ((a + c) << 1) + 1);
	}
	else
	{
		printf("%lld\n", ((b + c) << 1) + 1);
	}

	return 0;
}
