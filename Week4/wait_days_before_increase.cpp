class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> days(temperatures.size(), 0);
        int curr_temp, next_i, n = temperatures.size();

        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            curr_temp = temperatures[i];
            next_i = i + 1;

            while (temperatures[next_i] <= curr_temp)
            {
                if (days[next_i] == 0)
                {
                    next_i = i;
                    break;
                }
                else
                {
                    next_i += days[next_i];
                }
            }

            days[i] = next_i - i;
        }

        return days;        
    }
};