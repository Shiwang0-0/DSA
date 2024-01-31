

// APPROACH: 1   T.C:O(N^2) S.C:O(N)   ( NORMALLY MAKING A TREE FROM ARRAY)

// class Solution {
// public:

//     // TreeNode*makeBST(vector<int>& preorder,TreeNode* root,int i)
//     // {
//     //     if(root==NULL)
//     //     {
//     //         root = new TreeNode(preorder[i]);
//     //         return root;
//     //     }
//     //     if(root->val>preorder[i++])
//     //     {
//     //         root->left=makeBST(preorder,root->left,i);
//     //     }
//     //     if(root->val<preorder[i++])
//     //     {
//     //         root->right=makeBST(preorder,root->right,i);
//     //     }
//     //     return root;
//     // }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root=NULL;
//         return makeBST(preorder,root,0);
//     }
// };



// APPROACH: 2   T.C:O(N) S.C:O(N)

// class Solution {
// public:

//     TreeNode* makeBST(vector<int>preorder,int max, int min, int &i)
//     {
//         if(i>=preorder.size())
//             return NULL;
        
//         if(preorder[i]>max || preorder[i]<min)
//             return NULL;

//         TreeNode* root= new TreeNode(preorder[i++]);
  
//         root->left=makeBST(preorder,root->val,min,i);
//         root->right=makeBST(preorder,max,root->val,i);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int i=0;
//         return makeBST(preorder,INT_MAX,INT_MIN,i);
//     }
// };