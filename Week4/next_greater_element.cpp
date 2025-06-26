class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map <int, int> next_greater;
        vector<int> stack;
        int curr_num;

        for (int i = 0; i < nums2.size(); i++)
        {
            curr_num = nums2[i];
            
            while (stack.size() > 0 && curr_num > stack.back())
            {
                next_greater[stack.back()] = nums2[i];
                stack.pop_back();
            }

            stack.push_back(nums2[i]);
        }

        while (stack.size() > 0)
        {
            next_greater[stack.back()] = -1;
            stack.pop_back();
        }

        for (int x : nums1)
        {
            stack.push_back(next_greater.at(x));
        }

        return stack;
    }
};