#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
	int n;
	cin >> n;

	char prev = 0;
	char curr = 0;
	bool possible = 0;
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		prev = curr;
		cin >> curr;
		if (!possible && (curr < prev))
		{
			possible = true;
			idx = i;
		}
	}

	if (possible)
	{
		cout << "YES" << endl << idx << ' ' << idx + 1 << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
