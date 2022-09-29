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
    
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root){
        return {};
    }
    vector<vector<int>> result;
    queue<TreeNode*> queue1;

    queue1.push(root);

    while (!queue1.empty()){
        vector<int> level;
        int s = queue1.size();

        for (int i = 0; i < s; ++i) {
            TreeNode* node = queue1.front();
            queue1.pop();

            if (node->left){
                queue1.push(node->left);
            }
            if (node->right){
                queue1.push(node->right);
            }
            
            level.push_back(node->val);
        }
        result.push_back(level);
    }
    return result;
}

    
};