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
    vector<int> preorderTraversal(TreeNode* root) {
    	/* 
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        result.push_back(root->val);
        
        vector<int> temp = preorderTraversal(root->left);
        result.insert(result.end(), temp.begin(), temp.end());
        
        temp = preorderTraversal(root->right);
        result.insert(result.end(), temp.begin(), temp.end());
        */
		vector<int> result;
        stack<TreeNode*> mstack;
        
        if(root == NULL)
            return result;
        
        TreeNode* p = root;
        while(!mstack.empty() || p != NULL)
        {
           while(p != NULL)
           {
               mstack.push(p);   
               result.push_back(p->val);
               p = p->left;
           }
            
            if(!mstack.empty())
            {
                p = mstack.top();
                mstack.pop();
                p = p->right;
            }
        } 
        return result;
    }
};
