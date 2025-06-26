class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> max_heap;

        for (int x : nums)
        {
            max_heap.push(-x);
            if (max_heap.size() > k)
                max_heap.pop();
        }

        return - max_heap.top();
    }
};