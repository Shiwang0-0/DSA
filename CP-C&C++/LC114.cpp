// //Flatten Binary Tree to Linked List

// class Solution {
// public:

//     void preorder(TreeNode* root,vector<TreeNode*>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
//         v.push_back(root);
//         preorder(root->left,v);
//         preorder(root->right,v);
//     }

//     void flatten(TreeNode* root) {
//         if(root==NULL)
//         {
//             return;
//         }
//         vector<TreeNode*>v;
//         preorder(root,v);
//         root=v[0];
//         for(int i=0;i<v.size()-1;i++)
//         {
//            root->left=NULL;
//            root->right=v[i+1];
//            root=root->right;
//         }
//         root->left=NULL;
//         root->right=NULL;
//     }
// };