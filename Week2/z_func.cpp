#include <iostream>
using namespace std;

int* z_func(char* str, int n)
{
	int* z = new int[n];
	z[0] = 0;
	z[1] = 0;
	int j = 1;

	for (int i = 1; i < n; i++)
	{
		if (z[1] < z[i-1] - 1)
		{
			z[i] = z[1];
		}
		else
		{
			if (j < i)
			{
				j = i;
			}

			while(str[j] == str[j-i])
			{
				j++;
			}

			z[i] = j - i;
		}
	}

	return z;
}


int len(char* str, int max_len)
{
	int i = 0;
	while (i < max_len && str[i] != '\0')
	{
		i++;
	}

	return i;
}

int main()
{
	char s[100];
	cin >> s;
	int n = len(s, 100);

	int* z = z_func(s, n);

	for (int i = 0; i < n; i++)
	{
		cout << z[i] << ' ';
	}

	cout << endl;

}
