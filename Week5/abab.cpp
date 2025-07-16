#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
	long long int a, b, c;

	cin >> a >> b >> c;

	if (a == b)
	{
		cout << ((a + c) << 1) << endl;
	}
	else if (a < b)
	{
		cout << ((a + c) << 1) + 1 << endl;
	}
	else
	{
		cout << ((b + c) << 1) + 1 << endl;
	}

	return 0;
}
