class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map <int, int> frequencies;
        for (int num : nums)
        {
            frequencies[num] += 1;
        }

        vector<int> top_ele;
        vector<int> top_freq;
        auto it = frequencies.begin();
        top_ele.push_back(it->first);
        top_freq.push_back(it->second);
        cout << it->first << ' ' << it->second << endl;

        int start, end, mid;

        for(it++; it != frequencies.end(); it++)
        {
            
            if (it->second > top_freq.back())
            {
                start = 0, end = top_freq.size() - 1;
                while (start <= end)
                {
                    mid = (start + end)/2;
                    if (top_freq[mid] == it->second)
                    {
                        start = mid;
                        break;
                    }
                    else if (it->second > top_freq[mid])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }

                mid = (start + end)/2 + 1;


                top_ele.insert(top_ele.begin() + start, it->first);
                top_freq.insert(top_freq.begin() + start, it->second);

                if (top_ele.size() > k)
                {
                    top_ele.pop_back();
                    top_freq.pop_back();
                }
            }
            else if (top_ele.size() < k)
            {
                top_ele.push_back(it->first);
                top_freq.push_back(it->second);
            }
        }

        return top_ele;
        
    }
};