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
    vector<int> inorderTraversal(TreeNode* root) {
    	/* 
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        vector<int> temp = inorderTraversal(root->left);
        result.insert(result.end(), temp.begin(), temp.end());
        result.push_back(root->val);
        temp = inorderTraversal(root->right);
        result.insert(result.end(), temp.begin(), temp.end());
        
        return result;
        */
		
		vector<int> result;
        stack<TreeNode*> mstack;
        TreeNode* p = root;
        
        while(p != NULL || !mstack.empty())
        {
            while(p != NULL)
            {
                mstack.push(p);
                p = p->left;
            }
            if(!mstack.empty())
            {
                p = mstack.top();
                mstack.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result; 
    }
};
