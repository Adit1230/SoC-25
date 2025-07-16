/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<TreeNode*> curr_level;
        vector<TreeNode*> next_level;

        vector<vector<int>> ans;

        if (!root)
        {
            return ans;
        }
        
        curr_level.push_back(root);
        TreeNode* curr;

        while(!curr_level.empty())
        {
            vector<int>level;

            for (int i = 0; i < curr_level.size(); i++)
            {
                curr = curr_level[i];
                level.push_back(curr->val);

                if (curr->left)
                {
                    next_level.push_back(curr->left);
                }
                if (curr->right)
                {
                    next_level.push_back(curr->right);
                }
            }

            ans.push_back(level);
            curr_level.clear();
            swap(curr_level, next_level);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};