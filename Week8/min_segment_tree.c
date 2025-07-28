#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int max(int a, int b)
{
	if (a <= b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

void build(int v, int tl, int tr, int* a, int* tree)
{
	if (tl == tr)
	{
		tree[v] = a[tl];
	}
	else
	{
		int tm = (tl + tr)/2;
		build(2*v, tl, tm, a, tree);
		build(2*v + 1, tm+1, tr, a, tree);
		tree[v] = min(tree[2*v], tree[2*v + 1]);
	}

	return;
}

int tree_min(int* tree, int v, int tl, int tr, int l, int r)
{
	if (l > r)
	{
		return INT_MAX;
	}
	else if (l == tl && r == tr)
	{
		return tree[v];
	}
	
	int tm = (tl + tr)/2;

	return min(tree_min(tree, 2*v, tl, tm, l, min(r, tm)), tree_min(tree, 2*v + 1, tm+1, tr, max(tm+1, l), r) );
}

int main()
{
	int n, q, i, l, r;
	scanf("%d %d", &n, &q);

	int* a = malloc(n * sizeof(int));
	int* tree = malloc((4*n + 1) * sizeof(int));
	
	for (i = 0; i < n; ++i)
	{
		scanf(" %d", a+i);
	}

	build(1, 0, n-1, a, tree);
	free(a);

	for (i = 0; i < q; ++i)
	{
		scanf(" %d %d", &l, &r);
		--l;
		--r;
		printf("%d\n", tree_min(tree, 1, 0, n-1, l, r));
	}

	free(tree);

	return 0;
}
