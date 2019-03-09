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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> mstack;
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        TreeNode* cur = root;
        TreeNode* pre = root;
        mstack.push(cur);
        
        while(!mstack.empty())
        {
            cur = mstack.top();
            if( (cur->left == NULL && cur->right == NULL) 
               || (cur->left == pre || cur->right == pre) )
            {
                mstack.pop();
                result.push_back(cur->val);
                pre = cur;
            }
            else
            {
                if(cur->right != NULL)
                    mstack.push(cur->right);
                if(cur->left != NULL)
                    mstack.push(cur->left);
                
            }
        }
        return result;
    }
};
