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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  res;
        if(root==NULL)
            return res;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> temp1;
            vector<int> temp2;
             while(!s1.empty()){
                 TreeNode* top = s1.top();
                 s1.pop();
                 if(top->left)
                 s2.push(top->left);
                 if(top->right)
                     s2.push(top->right);
                 temp1.push_back(top->val);
             }
            if(temp1.size()!=0)
            res.push_back(temp1);
            while(!s2.empty()){
                 TreeNode* top = s2.top();
                 s2.pop();
                if(top->right)
                     s1.push(top->right);
                 if(top->left)
                 s1.push(top->left);
                 
                 temp2.push_back(top->val);
             }
            if(temp2.size()!=0)
            res.push_back(temp2);
        }
        return res;
    }
};
