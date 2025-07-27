#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
	int m, n, i, curr;
	long long int a, b, c;
	cin >> n >> m;

	vector<pair<int, long long int>> edges[n+1];

	for (i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		edges[a].push_back( make_pair(b, c) );
	}

	long long int dist[n+1];

	for (i = 0; i <= n; ++i)
	{
		dist[i] = LLONG_MIN;
	}

	dist[1] = 0;
	bool changed;
	vector<int> n_changed;

	for (i = 0; i < n; ++i)
	{
		changed = 0;
		n_changed.clear();

		for (curr = 1; curr <= n; ++curr)
		{
			if (dist[curr] == LLONG_MIN)
			{
				continue;
			}

			for (auto& edge : edges[curr])
			{
				a = dist[curr] + edge.second;
				if (a > dist[edge.first])
				{
					dist[edge.first] = a;
					changed = 1;
					n_changed.push_back(edge.first);
				}
			}
		}

		if (!changed)
		{
			break;
		}

	}

	if (changed)
	{
		vector<int> stack;
		bool visited[n+1];
		for (i = 0; i <= n; ++i)
		{
			visited[i] = 0;
		}

		for (int x : n_changed)
		{
			if (visited[x])
			{
				continue;
			}

			stack.push_back(x);
			visited[x] = 1;

			while (!stack.empty())
			{
				curr = stack.back();
				stack.pop_back();

				for (auto& edge : edges[curr])
				{
					if (!visited[edge.first])
					{
						stack.push_back(edge.first);
						visited[edge.first] = 1;
					}
				}
		
			}
		}

		if (visited[n])
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dist[n] << endl;
		}
		

	}
	else
	{
		cout << dist[n] << endl;
	}

	return 0;
	
}
