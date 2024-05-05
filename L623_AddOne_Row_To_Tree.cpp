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
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if (root == NULL) {
            return NULL;
        }
        if (curr == depth - 1) {
    TreeNode* tempL = root->left;
    TreeNode* tempR = root->right;
    root->left = new TreeNode(val);
    root->right = new TreeNode(val);
   root->left->left = tempL;
    root->right->right = tempR;
            return root;
        } else {
 root->left = add(root->left, val, depth, curr + 1);
root->right = add(root->right, val, depth, curr + 1);
            return root;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> Que;
        //Que.push(root);
        int currentDepth=1;
        if(depth ==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int curr=1;
        return add(root, val,depth,currentDepth);
        // while(!Que.empty()){
        //     int size=Que.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* node=Que.front();
        //         Que.pop();

        //         if(currentDepth==depth-1){
        //             TreeNode* leftChild=new TreeNode(val);
        //             TreeNode* rightChild=new TreeNode(val);
        //             leftChild->left=node->left;
        //             rightChild->left=node->right;
        //             node->left=leftChild;
        //             node->right=rightChild;
        //         }
        //         else{
        //             if(node->left)Que.push(node->left);
        //             if(node->right)Que.push(node->right);
        //         }
        //     }
        // }return root;
    }
};