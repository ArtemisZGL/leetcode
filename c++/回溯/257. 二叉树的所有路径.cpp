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
 �򵥵ݹ飬Ҳû�õ����ݣ�������������ʲô��Ҳ����������ϣ���Ҳ����vistited �����Ľṹ�� 
 */ 
class Solution {
public:
    void btsearch(vector<string>& ans, TreeNode* curNode, string preStr)
    {
        //Ҷ�ӽڵ�
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
