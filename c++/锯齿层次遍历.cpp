/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> mque;
        mque.push(root);
        vector<int> level;
        int curCount = 1;
        int nextCount = 0;
        bool isLeft = true;
        
        while(!mque.empty())
        {
            while(curCount != 0)
            {
                TreeNode* top = mque.front();
                mque.pop();
                curCount--;
                level.push_back(top->val);
                if(top->left != NULL)
                {
                    mque.push(top->left);
                    nextCount++;
                }
                if(top->right != NULL)
                {
                    mque.push(top->right);
                    nextCount++;
                }
            }
            
            if(!isLeft)
            {
                vector<int> temp;
                vector<int>::reverse_iterator iter;
                for(iter = level.rbegin(); iter!= level.rend(); iter++)
                    temp.push_back(*iter);
                
                level = temp;
            }
            isLeft = !isLeft;
            curCount = nextCount;
            nextCount = 0;
            result.push_back(level);
            level.clear();
        }
        return result;
    }
};
