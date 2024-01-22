// Kth Smallest Element in a BST



// RECURSIVE APPROACH

// class Solution {
// public:
// int count=0;
// int ans=-1;

//     void func(TreeNode* root,int k)
//     {
//         if(root==NULL)
//             return;
        
//         //first reach to the smallest element
//         func(root->left,k);

//         // when comming back from the smallest element, count it as 1.
//         count=count+1;
//         if(count==k)
//         {
//             ans=root->val;
//             return;
//         }

//         // then go to right element
//         func(root->right,k);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         func(root,k);
//         return ans;
//     }
// };