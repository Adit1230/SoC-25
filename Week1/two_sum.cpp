class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> map;
        const int n = nums.size();
        vector<int> ans(2, 0);

        for(int i = 0; i < n; ++i)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                ans[0] = i;
                ans[1] = map[target - nums[i]];
                return ans;
            }
            else
            {
                map[nums[i]] = i;
            }
        }

        return ans; 
    }
};