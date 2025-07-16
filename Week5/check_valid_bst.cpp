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
    bool isValidBST(TreeNode* root, long long int min_val = (long long int) INT_MIN - 1, long long int max_val = (long long int) INT_MAX + 1)
    {
        if (!root)
        {
            return true;
        }
        else if (root->left && ((root->left->val >= root->val) || (root->left->val <= min_val)) )
        {
            return false;
        }
        else if (root->right && ((root->right->val <= root->val) || (root->right->val >= max_val)) )
        {
            return false;
        }
        else
        {
            return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
        }

    }
};