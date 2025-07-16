#include <iostream>
using std::cin, std::cout, std::endl;

long long int diff (long long int a, long long int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int main()
{
	int n_tests;
	int n, k, a, b, i, waste;
	long long int *xs, *ys, xa, ya, xb, yb, min_a, min_b;

	for (cin >> n_tests; n_tests > 0; --n_tests)
	{
		cin >> n >> k >> a >> b;
		--a;
		--b;
		xs = new long long int[k];
		ys = new long long int[k];

		for (i = 0; i < k; ++i)
		{
			cin >> xs[i] >> ys[i];
		}

		if (a < k)
		{
			xa = xs[a];
			ya = ys[a];
		}
	
		if (b < k)
		{
			xb = xs[b];
			yb = ys[b];
		}
		
		for (i = k; i < n; ++i)
		{
			if (i == a)
			{
				cin >> xa >> ya;
			}
			else if (i == b)
			{
				cin >> xb >> yb;
			}
			else
			{
				cin >> waste >> waste;
			}
		}

		min_a = 1e10;
		min_b = 1e10;

		for (i = 0; i < k; ++i)
		{
			if (diff(xs[i], xa) + diff(ys[i], ya) < min_a)
			{
				min_a = diff(xs[i], xa) + diff(ys[i], ya);
			}
			if (diff(xs[i], xb) + diff(ys[i], yb) < min_b)
			{
				min_b = diff(xs[i], xb) + diff(ys[i], yb);
			}
		}

		min_b += min_a;
		min_a = diff(xa, xb) + diff(ya, yb);

		if (min_a > min_b)
		{
			cout << min_b << endl;
		}
		else
		{
			cout << min_a << endl;
		}

		delete[] xs;
		delete[] ys;

	}

	return 0;
}
