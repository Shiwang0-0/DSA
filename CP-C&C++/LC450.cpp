// Deletion of Node in BST


// class Solution {
// public:

//     TreeNode* inOrderPredecessor(TreeNode* root){
//         while(root->right!=NULL)
//         {        
//                 root=root->right;
//         }
//     return root;
//     }

//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==NULL)
//         {
//             return root;
//         }
//         else if(root->val == key)
//         {
//             // No Tree

//             // root element only
//             if(root->left==NULL && root->right==NULL)
//             {
//                 delete root;
//                 return NULL;
//             }

//             // 1 child only
//             if(root->left!=NULL && root->right==NULL)
//             {
//                 TreeNode* temp=root->left;
//                 delete root;
//                 return temp;
//             }

//             if(root->left==NULL && root->right!=NULL)
//             {
//                 TreeNode* temp=root->right;
//                 delete root;
//                 return temp;
//             }

//             // 2 child
//             if(root->left!=NULL && root->right!=NULL)
//             {
//                 int predecessor = inOrderPredecessor(root->left)->val;
//                 root->val=predecessor;
//                 root->left= deleteNode(root->left,predecessor);
//                 return root;
//             }
//         }
//         else if(root->val > key)
//         {
//             root->left=deleteNode(root->left,key);
//             return root;
//         }
//         else
//         {
//             root->right=deleteNode(root->right,key);
//             return root;
//         }
//        return root; 
//     }
// };