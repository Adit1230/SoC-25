#include <stdio.h>

int main()
{
	int n, ax, ay, bx, by, cx, cy;
	scanf("%d", &n);
	scanf("%d %d", &ax, &ay);
	scanf("%d %d", &bx, &by);
	scanf("%d %d", &cx, &cy);

	bx = bx > ax;
	by = by > ay;
	
	cx = cx > ax;
	cy = cy > ay;

	if (bx == cx && by == cy)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
