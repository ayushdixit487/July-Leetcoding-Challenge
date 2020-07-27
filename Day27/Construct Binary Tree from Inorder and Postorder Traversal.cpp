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
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {  
     return create(in, po, 0, in.size() - 1, 0,po.size() - 1);
   }

TreeNode* create(vector<int> &in, vector<int> &po, int is, int ie, int ps, int pe){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(po[pe]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(in[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(in, po, is, pos - 1, ps, ps + pos - is - 1);
    node->right = create(in, po, pos + 1, ie, pe - ie + pos, pe - 1);
    return node;
}
};
