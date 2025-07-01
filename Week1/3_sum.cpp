class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i, low, high;
        vector<vector<int>>ans;
        vector<int> triplet(3, 0);

        for (i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            low = i+1, high = nums.size() - 1;

            while (low < high)
            {
                if (nums[low] + nums[high] > -nums[i])
                {
                    --high;
                }
                else if (nums[low] + nums[high] < -nums[i])
                {
                    ++low;
                }
                else
                {
                    triplet[0] = nums[i];
                    triplet[1] = nums[low];
                    triplet[2] = nums[high];
                    ans.push_back(triplet);

                    while(low < high && nums[low + 1] == nums[low])
                    {
                        ++low;
                    }
                    while(low < high && nums[high - 1] == nums[high])
                    {
                        --high;
                    }

                    ++low;
                    --high;
                }
            }
        }

        return ans;
    }

};