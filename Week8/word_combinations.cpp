#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

class Trie
{
	public:
	Trie* next[26];
	bool is_word;

	Trie()
	{
		for (int i = 0; i < 26; ++i)
		{
			next[i] = nullptr;
		}

		is_word = false;
	}

	~Trie()
	{
		for (int i = 0; i < 26; ++i)
		{
			if(next[i])
			{
				delete next[i];
			}
		}
	}

	void add_word(const string& s)
	{
		Trie* curr = this, *n;

		for (int i  = 0; i < s.size(); ++i)
		{
			n = (curr->next[s[i] - 'a']);
			if (!n)
			{
				n = new Trie;
				curr->next[s[i] - 'a'] = n;
			}

			curr = n;
		}

		curr->is_word = true;
	}

};

string str;
int n, x, *ways;
const int mod = 1e9 + 7;
Trie* dictionary = new Trie;

int calc_ways(int i)
{
	if (ways[i] >= 0)
	{
		return ways[i];
	}

	Trie* curr = dictionary;
	int original_i = i;
	long long int ans = 0;

	for (; i < x; ++i)
	{
		curr = curr->next[str[i] - 'a'];

		if (!curr)
		{
			break;
		}

		if (curr->is_word)
		{
			ans = (ans + calc_ways(i+1)) % mod;
		}
		
	}

	ways[original_i] = ans;
	return ans;
}

int main()
{
	cin >> str;
	x = str.size();
	cin >> n;

	int i;
	string s;

	for (i = 0; i < n; ++i)
	{
		cin >> s;
		dictionary->add_word(s);
	}

	ways = new int[x + 1];
	
	for (i = 0; i < x; ++i)
	{
		ways[i] = -1;
	}
	ways[x] = 1;

	int ans = calc_ways(0);
	cout << ans << endl;

	delete[] ways;
	delete dictionary;
	return 0;
}
