//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL)
//         {
//             return root;
//         }
//         if(p==root || q==root)
//         {
//             return root;
//         }


//         TreeNode* left=lowestCommonAncestor(root->left , p,  q);
//         TreeNode* right=lowestCommonAncestor(root->right , p,  q);

//         if(left!=NULL && right!=NULL)
//         {
//             return root;
//         }
//         if(left==NULL && right!=NULL)
//         {
//             return right;
//         }
//         if(left!=NULL && right==NULL)
//         {
//             return left;
//         }
//         else
//         {
//             return NULL;
//         }
//     }
// };