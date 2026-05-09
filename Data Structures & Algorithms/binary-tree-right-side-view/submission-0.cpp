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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            if(res.size() == curr.second) res.push_back({});
            res[curr.second].push_back(curr.first->val);

            if(curr.first->left != nullptr)q.push({curr.first->left, curr.second+1});
            if(curr.first->right != nullptr)q.push({curr.first->right, curr.second+1});
        }

        vector<int> e(res.size());
        for(int i = 0; i < res.size(); i++){
            e[i] = res[i][res[i].size()-1];
        }
        return e;
    }
};
