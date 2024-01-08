// Range Sum of BST
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].



// class Solution {
// public:
//     int solve(TreeNode* root, int low, int high)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         if(root->val>=low && root->val<=high)
//         {
//           return root->val+solve(root->right,low,high)+solve(root->left,low,high);
//         }
//         else if(root->val>low)
//         {
//             return solve(root->left,low,high);
//         }
//         else
//         {
//             return solve(root->right,low,high);
//         }
//     }

//     int rangeSumBST(TreeNode* root, int low, int high) {
//         int ans=solve(root,low,high);
//         return ans;
//     }
// };