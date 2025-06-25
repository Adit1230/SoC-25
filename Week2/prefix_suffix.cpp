#include <iostream>
using std::cin, std::cout, std::endl;
#include <string>
using std::string;

void print_ans(const string& str, const int& ans)
{
	for (int i = 0; i < ans; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	string str;
	cin >> str;
	int n = str.length();
	int lps[n] = {0};
	int i = 1, len = 0;

	if (n <= 2)
	{
		cout << "Just a legend" << endl;
		return 0;
	}


	while (i < n)
	{
		if (str[i] == str[len])
		{
			lps[i++] = ++len;
		}
		else if (len == 0)
		{
			lps[i++] = 0;
		}
		else
		{
			len = lps[len - 1];
		}
	}

	int ans = lps[n-1];
	
	if (ans == 0)
	{
		cout << "Just a legend" << endl;
		return 0;
	}
	else if (ans == n - 1)
	{
		print_ans(str, n - 2);	
		return 0;
	}

	i = 1;
	len = 0;
	int max = 0;
	
	while (i < n - 1)
	{
		if (str[i] == str[len])
		{
			++i;
			++len;
		}
		else if (len == 0)
		{
			++i;
		}
		else
		{
			len = lps[len - 1];
		}

		if (len > max)
		{
			max = len;
		}

		if (len == ans)
		{
			break;
		}
	}

	if (i == n-1)
	{
		while(ans != 0)
		{
			if (max >= ans)
			{
				print_ans(str, ans);
				return 0;
			}
			ans = lps[ans-1];
		}

		cout << "Just a legend" << endl;
	}
	else
	{
		print_ans(str, ans);	
	}
	
	return 0;
}
