/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int n = 0;
        return LCA(root, p, q, n);        
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q, int& n)
    {
        int x = n;
        
        if (root == 0)
        {
            return 0;
        }
        else if (root == p || root == q)
        {
            ++n;
            if (n == 2)
            {
                return 0;
            }
        }


        TreeNode* a = LCA(root->left, p, q, n);
        if (a != 0)
        {
            return a;
        }
        
        a = LCA(root->right, p, q, n);
        if (a != 0)
        {
            return a;
        }

        if (n == x + 2)
        {
            return root;
        }
        else
        {
            return 0;
        }
    }
};