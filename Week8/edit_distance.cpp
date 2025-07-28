#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main()
{
	string str1, str2;

	cin >> str1;
	cin >> str2;

	int distance[str1.size() + 1][str2.size() + 1], i, j;

	for (i = 0; i <= str1.size(); ++i)
	{
		distance[i][0] = i;
	}
	
	for (j = 0; j <= str2.size(); ++j)
	{
		distance[0][j] = j;
	}

	for (i = 1; i <= str1.size(); ++i)
	{
		for (j = 1; j <= str2.size(); ++j)
		{
			if (str1[i-1] == str2[j-1])
			{
				distance[i][j] = distance[i-1][j-1];
			}
			else
			{
				distance[i][j] = std::min( std::min(distance[i-1][j], distance[i][j-1]) , distance[i-1][j-1]) + 1;
			}
		}
	}

	cout << distance[str1.size()][str2.size()] << endl;


	return 0;
}
