#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	printf("%d\n", n > 28 ? m : m & (~(-1 << n)));
	
	return 0;
}
