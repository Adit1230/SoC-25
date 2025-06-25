#include <iostream>
#include <string>
#include <vector>
using std::cin, std::cout, std::endl;
using std::string, std::vector;

vector<int> find(string& str, string& pat)
{
	vector<int> lps(pat.length(), 0);
	int len = 0;
	int i = 1;
	int l_str = str.length();
	int l_pat = pat.length();

	while (i < l_pat)
	{
		if (pat[i] == pat[len])
		{
			++len;
			lps[i] = len;
			++i;
		}
		else if (len == 0)
		{
			lps[i] = 0;
			++i;
		}
		else
		{
			len = lps[len - 1];
		}
	}

	i = 0;
	int match = 0;
	vector<int> indices;

	while (i < l_str)
	{

		if (str[i] == pat[match])
		{
			++i;
			++match;
		}		
		else if (match == 0)
		{
			++i;
		}
		else
		{
			match = lps[match - 1];
		}

		if (match == l_pat)
		{
			indices.push_back(i - l_pat);
			match = lps[l_pat - 1];
		}
	}

	return indices;
}

int main()
{
	string a = "abbabbaabcaabba";
	string b = "abba";
	vector<int> idx = find(a, b);
	for (int i : idx)
		cout << i << endl;

	return 0;
}
