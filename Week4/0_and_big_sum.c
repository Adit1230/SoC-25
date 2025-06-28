#include <stdio.h>

int main()
{
	unsigned int n_testcases, n, k;
	unsigned long long int x;
	const unsigned int mod = 1000000007;

	scanf("%u", &n_testcases);

	for (; n_testcases > 0; --n_testcases)
	{
		scanf("%u", &n);
		scanf("%u", &k);

		x = n;

		for(; k>1; --k)
		{
			x = (x * n) % mod;
		}

		printf("%llu\n", x);

	}
	return 0;
}
