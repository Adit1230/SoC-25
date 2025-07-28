#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);

	int prev[6] = {1, 1};
	int curr = 1;

	for (i = 1; i < n; ++i)
	{
		curr = ( ((long long int) prev[0]) + prev[1] + prev[2] + prev[3] + prev[4] + prev[5]) % 1000000007;
		prev[5] = prev[4];
		prev[4] = prev[3];
		prev[3] = prev[2];
		prev[2] = prev[1];
		prev[1] = prev[0];
		prev[0] = curr;
	}

	printf("%d\n", curr);
	
	return 0;
}
