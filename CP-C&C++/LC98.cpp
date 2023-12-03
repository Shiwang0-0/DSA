// Vadiate wheter the tree is BST or not


// class Solution {
// public:

//     bool check(TreeNode* root,long min,long max)
//     {
//         if(root==NULL)
//         {
//             return true;
//         }
//         if(root->val <=min || root->val >=max )
//         {
//             return false;
//         }
//         bool left=check(root->left,min,root->val);
//         bool right=check(root->right,root->val,max);
//         return left && right;
//     }

//     bool isValidBST(TreeNode* root) {
//         if(!root->left && !root->right)
//         {
//             return true;
//         }
//         return check(root,LONG_MIN,LONG_MAX);
//     }
// };