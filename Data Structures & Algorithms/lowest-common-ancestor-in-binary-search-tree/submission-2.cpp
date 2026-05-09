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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* pointer = root;
        while(true){
            if((pointer->val > p->val && pointer->val < q->val) || (pointer->val < p->val && pointer->val > q->val)){
                return pointer;
            }else if(pointer->val == p->val || pointer->val == q->val){
                return pointer;
            }else if(pointer->val > p->val && pointer->val > q->val){
                pointer = pointer->left;
            }else{
                pointer = pointer->right;
            }
        }
    }
};