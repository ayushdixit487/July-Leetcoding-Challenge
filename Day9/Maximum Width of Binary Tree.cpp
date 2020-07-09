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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int maxWidth = 1;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            while(!dq.empty()&&dq.front()==NULL)
                dq.pop_front();
            while(!dq.empty() && dq.back()==NULL)
                dq.pop_back();
             int size = dq.size();
            maxWidth = max(maxWidth,size);
           
            for(int  i=0;i<size;i++){
                TreeNode* front = dq.front();
                dq.pop_front();
                if(front==NULL){
                    dq.push_back(NULL);
                    dq.push_back(NULL);
                }else{
                    dq.push_back(front->left);
                    dq.push_back(front->right);
                }
            }
        }
        
        return maxWidth;
        
    }
};
