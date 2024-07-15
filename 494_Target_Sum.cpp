class Solution
{
public:
    // struct TreeNode {
    //     int val;
    //     char operation;
    //     TreeNode* root;
    //     TreeNode* left;
    //     TreeNode* right;
    //   TreeNode(char op){
    //       this->op=operation;
    //       this->left=this->right=NULL;
    //       this->op=operation;
    //   }
    // };

    // int countPaths(TreeNode* root, int targetSum) {
    //     if (!root)
    //         return 0;
    //     if (!root->left && !root->right) {
    //         return (targetSum == 0 && root->operation == '+') || (targetSum == 0 && root->operation == '-') ? 1 : 0;
    //     }
    //     int count = 0;
    //     if (root->operation == '+') {
    //         count += countPaths(root->left, targetSum - root->left->val);
    //         count += countPaths(root->right, targetSum - root->right->val);
    //     } else if (root->operation == '-') {
    //         count += countPaths(root->left, targetSum + root->left->val);
    //         count += countPaths(root->right, targetSum + root->right->val);
    //     }
    //     return count;
    // }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     queue<TreeNode*> q;
    //     TreeNode* root = new TreeNode('+');
    //     q.push(root);

    //     for (int num : nums) {
    //         int size = q.size();
    //         for (int i = 0; i < size;i++) {
    //             TreeNode* curr = q.front();
    //             q.pop();
    //             TreeNode* add = new TreeNode('+');
    //             TreeNode* sub = new TreeNode('-');
    //             add->left = curr;
    //             add->right = new TreeNode(num);
    //             sub->left = curr;
    //             sub->right = new TreeNode(-num);
    //             q.push(add);
    //             q.push(sub);
    //         }
    //     }
    //     return countPaths(root, target);
    // }
    // Recc
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<string, int> memo;

        return helper(nums, 0, 0, target, memo);
    }
    int helper(vector<int> &nums, int index, int currentSum, int target, unordered_map<string, int> &memo)
    {
        if (index == nums.size())
            return (currentSum == target) ? 1 : 0;

        string key = to_string(index) + "," + to_string(currentSum);
        if (memo.find(key) != memo.end())
            return memo[key];

        int addways = helper(nums, index + 1, currentSum + nums[index], target, memo);
        int subways = helper(nums, index + 1, currentSum - nums[index], target, memo);
        memo[key] = addways + subways;
        return memo[key];
    }

    // DP
    /*
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum=0;
        for(int num: nums){
            sum+=num;
        }
        if(sum< target||){}

    }
    */
};