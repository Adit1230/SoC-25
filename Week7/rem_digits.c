#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int num, max_digit, ans = 0;

	while (n > 0)
	{
		num = n;
		max_digit = 0;
		while (num > 0)
		{
			if (num % 10 > max_digit)
			{
				max_digit = num % 10;
			}
			num /= 10;
		}
		n -= max_digit;
		++ans;
	}

	printf("%d\n", ans);

	return 0;
}
