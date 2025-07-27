#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl, std::sort; 

int main()
{
	int n, x, i, j;
	cin >> n >> x;
	int coins[n];
	
	for (i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}

	int prev[x+1], curr, min_coins;
	prev[0] = 0;
	sort(coins, coins+n);
	

	for (i = 1; i <= x; ++i)
	{
		min_coins = -1;
		for (j = 0; j < n; ++ j)
		{
			if (coins[j] > i)
			{
				break;
			}
			
			curr = prev[i - coins[j]] + 1;

			if (curr && (curr < min_coins || min_coins == -1))
			{
				min_coins = curr;
			}
		}

		prev[i] = min_coins;
	}

	cout << prev[x] << endl;


	return 0;
}
