/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
 简单递归，也没用到回溯（不是用来搜索什么，也不是排列组合），也不用vistited （树的结构） 
 */ 
class Solution {
public:
    void btsearch(vector<string>& ans, TreeNode* curNode, string preStr)
    {
        //叶子节点
        if(curNode->left == NULL && curNode->right == NULL)
            ans.push_back(preStr + to_string(curNode->val));
        else
        {
            preStr = preStr + to_string(curNode->val) + "->";
            if(curNode->left != NULL)
                btsearch(ans, curNode->left, preStr);
            if(curNode->right != NULL)
                btsearch(ans, curNode->right, preStr);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL)
            return ans;
        
        btsearch(ans, root, "");
        return ans;
    }
};
