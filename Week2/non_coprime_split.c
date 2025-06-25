#include <stdio.h>
#include <math.h>

long long int factorise(long long int x)
{
	if (x%2 == 0)
		return 2;

	long long int s = sqrt(x);

	for (int i = 3; i <= s; i+=2)
	{
		if (x % i == 0)
		{
			return i;
		}
	}

	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long int x, y;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		scanf("%lld", &y);
		
		if (x == 1 || x == 2)
			x = 3;
		
		if (x == y)
		{
			long long int factor = factorise(x);

			if (!factor)
			{
				printf("%d\n", -1);
			}
			else
			{
				printf("%lld %lld\n", factor, x-factor);
			}
		}
		else if (x > y)
		{
			printf("%d\n", -1);
		}
		else if (x & 1)
		{
			printf("%d %lld\n", 2, x-1);
		}
		else
		{
			printf("%d %lld\n", 2, x-2);
		}
		
	}
	return 0;
}
