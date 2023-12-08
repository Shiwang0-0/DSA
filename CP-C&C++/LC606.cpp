// Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

// Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
// we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
// Ex:Input: root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"


// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         if(root==NULL)
//         {
//             return "";
//         }
//         string str=to_string(root->val);
//         if(root->left)
//         {
//             str=str+"("+tree2str(root->left)+")";
//         }
//         else if(!root->left && root->right)
//         {
//             str=str+"("+")";
//         }
//         if(root->right)
//         {
//             str=str+"("+tree2str(root->right)+")";
//         }
//     return str;
//     }
// };