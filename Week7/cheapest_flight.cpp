#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int main()
{
	int m, n, i;
	long long int a, b, c;
	cin >> n >> m;

	vector<pair<int, int>> flights[n+1];

	for (i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		flights[a].push_back( make_pair(b, c) );
	}

	long long int dist[n+1][2];
	priority_queue<tuple<long long int, int, bool>, vector<tuple<long long int, int, bool>>, greater<>> heap; 

	for (i = 0; i <= n; ++i)
	{
		dist[i][0] = LLONG_MAX;
		dist[i][1] = LLONG_MAX;
	}

	dist[1][0] = 0;
	heap.emplace(0, 1, 0);

	while (!heap.empty())
	{
		auto [c, curr, b] = heap.top();
		heap.pop();

		if (dist[curr][b] < c)
		{
			continue;
		}

		for (auto& x : flights[curr])
		{
			a = c + x.second;
			if (a < dist[x.first][b])
			{
				dist[x.first][b] = a;
				heap.emplace(a, x.first, b);
			}

			if (!b)
			{
				a = c + (x.second / 2);

				if (a < dist[x.first][1])
				{
					dist[x.first][1] = a;
					heap.emplace(a, x.first, 1);
				}
			}
		}

	}

	cout << dist[n][1] << endl;
	
}
