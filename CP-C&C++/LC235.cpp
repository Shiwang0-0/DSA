// Lowest Common Ancestor of a Binary Search Tree


// // RECURSIVE
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL)
//         {
//             return root;
//         }
//         if(root->val < p->val && root->val < q->val)
//         {
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         if(root->val > p->val && root->val > q->val)
//         {
//             return lowestCommonAncestor(root->left, p, q);
//         }
//             return root;
//     }
// };



// // ITERATIVE
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         while(root!=NULL)
//         {
//             if(root->val < p->val && root->val < q->val)
//             {
//                 root=root->right;
//             }
//             else if(root->val > p->val && root->val > q->val)
//             {
//                 root=root->left;
//             }  
//             else
//             {
//                 break;
//             }
//         }
//         return root;
//     }
// };