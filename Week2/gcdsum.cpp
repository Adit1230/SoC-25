#include <iostream>
using std::cin, std::cout, std::endl;

bool sum_coprime(unsigned long long int x, int sum)
{
	if (!(x%3))
	{
		return true;
	}

	if (!(x%2 | sum%2))
	{
		return true;
	}

	int temp;

	while (sum > 0)
	{
		temp = sum;
		sum = x%sum;
		x = temp;		
	}

	if (x > 1)
	{
		return true;
	}
	
	return false;

}

int main()
{
	int n;
	cin >> n;
	unsigned long long int x, temp_x;
	int sum;

	for (int i = 0; i<n; i++)
	{
		cin >> x;
		temp_x = x;
		sum = 0;

		while (temp_x > 0)
		{
			sum += temp_x % 10;
			temp_x /= 10;
		}

		while(true)
		{
			if(sum_coprime(x, sum))
			{
				cout << x << endl;
				break;
			}
			
			if((++x) % 10 == 0)
			{
				temp_x = x;
				sum = 0;
	
				while (temp_x > 0)
				{
					sum += temp_x % 10;
					temp_x /= 10;
				}

			}
			else
			{
				++sum;
			}

		}
		
	}

	return 0;
}
