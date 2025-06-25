#include <iostream>
using std::cin, std::cout, std::endl;

void equalise_price()
{
	int n;
	long long int k, x, min, max;

	cin >> n >> k;
	cin >> x;
	min = max = x;

	for (int i = 1; i < n; i++)
	{
		cin >> x;
		
		if (x > max)
			max = x;
		else if (x < min)
			min = x;
	}

	if (max - k > min + k)
		cout << -1 << endl;
	else
		cout << min + k << endl;

}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		equalise_price();
	}

	return 0;
}
