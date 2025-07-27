#include <iostream>
#include <vector>
#include <queue>
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

	bool visited[n+1];
	long long int dist[n+1];
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> heap; 

	for (i = 0; i <= n; ++i)
	{
		visited[i] = 0;
		dist[i] = LLONG_MAX;
	}

	dist[1] = 0;
	heap.emplace(0, 1);

	while (!heap.empty())
	{
		auto [a, curr] = heap.top();
		heap.pop();

		if (visited[curr])
		{
			continue;
		}

		visited[curr] = 1;

		for (auto& x : flights[curr])
		{
			a = dist[curr] + x.second;
			if (a < dist[x.first])
			{
				dist[x.first] = a;
				heap.emplace(a, x.first);
			}
		}

	}

	for ( i = 1; i <= n; ++i)
	{
		cout << dist[i] << ' ';
	}
	cout << endl;
	
}
