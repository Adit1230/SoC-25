#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a, b, c, d;

	for (; n>0; --n)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		scanf("%d", &d);
		
		d -= b;
		c = d - c + a;

		if (c < 0 || d < 0)
		{
			printf("%d\n", -1);
		}
		else
		{
			printf("%d\n", c + d);
		}

	}
	return 0;
}
