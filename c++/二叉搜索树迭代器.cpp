/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    queue<int> nextVal;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> mstack;
        TreeNode* p = root;
        while(!mstack.empty() || p != NULL)
        {
            while(p != NULL)
            {
                mstack.push(p);
                p = p->left;
            }
            if(!mstack.empty())
            {
                p = mstack.top();
                nextVal.push(p->val);
                mstack.pop();
                p = p->right;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int temp = nextVal.front();
        nextVal.pop();
        return temp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nextVal.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
