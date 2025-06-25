#include <iostream>
using std::cin, std::cout, std::endl;

int n_moves()
{
	int n;
	cin >> n;
	char bracs[n+1] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> bracs[i];
	}

	int unclosed = 0;

	for (char* c = bracs; *c != '\0'; ++c)
	{
		if (*c == '(')
		{
			++unclosed;
		}
		else if (unclosed > 0)
		{
			--unclosed;
		}
		
	}

	return unclosed;
}

int main()
{
	int n;
	cin >> n;

	int ans[n];

	for (int i = 0; i < n; ++i)
	{
		ans[i] = n_moves();
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}
