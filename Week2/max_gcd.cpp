#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
	int n;
	cin >> n;
	unsigned long long int x, y, max, shift;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x > y)
			max = x - y;
		else if (x < y)
			max = y - x;
		else
		{
			cout << 0 << ' ' << 0 << endl;
			continue;
		}

		shift = x % max;

		if (shift > max - shift)
			shift = max - shift;

		cout << max << ' ' << shift << endl;


	}

	return 0;
}
