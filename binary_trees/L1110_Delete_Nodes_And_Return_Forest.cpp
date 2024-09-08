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

class Solution
{
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> res;
        queue<TreeNode *> Que;
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        function<TreeNode *(TreeNode *, bool)>
            dfs = [&](TreeNode *node, bool isRoot) -> TreeNode *
        {
            if (node == NULL)
                return NULL;
            bool deleted = toDeleteSet.count(node->val) > 0;
            if (isRoot && !deleted)
            {
                res.push_back(node);
            }
            node->left = dfs(node->left, deleted);
            node->right = dfs(node->right, deleted);
            return deleted ? NULL : node;
        };
        dfs(root, true);
        return res;
    }
};

// class Solution {
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         vector<TreeNode*> res;
//         queue<TreeNode*> Que;
//         unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());

//         // Function to check and add a node to the queue and result
//         auto checkAndAdd = [&](TreeNode* node, bool isRoot) {
//             if (!node) return;
//             if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
//                 Que.push(node);
//             } else {
//                 if (isRoot) res.push_back(node);
//                 Que.push(node);
//             }
//         };

//         checkAndAdd(root, true);

//         while (!Que.empty()) {
//             TreeNode* node = Que.front();
//             Que.pop();

//             if (node == nullptr) continue;

//             if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
//                 checkAndAdd(node->left, true);
//                 checkAndAdd(node->right, true);
//             } else {
//                 if (node->left != nullptr && toDeleteSet.find(node->left->val) != toDeleteSet.end()) {
//                     checkAndAdd(node->left->left, true);
//                     checkAndAdd(node->left->right, true);
//                     node->left = nullptr;
//                 } else if (node->left != nullptr) {
//                     Que.push(node->left);
//                 }

//                 if (node->right != nullptr && toDeleteSet.find(node->right->val) != toDeleteSet.end()) {
//                     checkAndAdd(node->right->left, true);
//                     checkAndAdd(node->right->right, true);
//                     node->right = nullptr;
//                 } else if (node->right != nullptr) {
//                     Que.push(node->right);
//                 }
//             }
//         }

//         return res;
//     }
// };
