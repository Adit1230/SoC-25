#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
	int n;
	cin >> n;

	long long int max_area[4], min_b, max_b, w, h, k, x, ans;

	for (; n > 0; --n)
	{
		cin >> w >> h;
		
		min_b = w;
		max_b = 0;
		
		for (cin >> k, cin >> x, min_b = max_b = x; k > 1; --k)
		{
			cin >> x;

			if (x < min_b)
			{
				min_b = x;
			}
			else if (x > max_b)
			{
				max_b = x;
			}
		}

		max_area[0] = (max_b - min_b) * h;
		

		min_b = w;
		max_b = 0;
		
		for (cin >> k, cin >> x, min_b = max_b = x; k > 1; --k)
		{
			cin >> x;

			if (x < min_b)
			{
				min_b = x;
			}
			else if (x > max_b)
			{
				max_b = x;
			}
		}

		max_area[1] = (max_b - min_b) * h;

	
		min_b = h;
		max_b = 0;
		
		for (cin >> k, cin >> x, min_b = max_b = x; k > 1; --k)
		{
			cin >> x;

			if (x < min_b)
			{
				min_b = x;
			}
			else if (x > max_b)
			{
				max_b = x;
			}
		}

		max_area[2] = (max_b - min_b) * w;

	
		min_b = h;
		max_b = 0;
		
		for (cin >> k, cin >> x, min_b = max_b = x; k > 1; --k)
		{
			cin >> x;

			if (x < min_b)
			{
				min_b = x;
			}
			else if (x > max_b)
			{
				max_b = x;
			}
		}

		max_area[3] = (max_b - min_b) * w;


		ans = max_area[0];
		for (x = 1; x < 4; ++x)
		{
			if (max_area[x] > ans)
			{
				ans = max_area[x];
			}
		}

		cout << ans << endl;

	}
	
	return 0;
}
