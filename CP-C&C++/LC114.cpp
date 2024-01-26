// //Flatten Binary Tree to Linked List


// APPROACH: 1  (VECTOR)   T.C: O(N)   S.C: O(N)

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



// APPROACH: 2  (MORRIS ORDER TRAVERSAL)   T.C: O(N)   S.C: O(1)

/*
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        TreeNode* current=root;
        while(current)
        {
            if(current->left)
            {
                TreeNode* pred=current->left;
                while(pred->right)
                {
                    pred=pred->right;
                }
                pred->right=current->right;
                current->right=current->left;
                current->left=NULL; // marking left as NULL for all nodes(condition given in question)
            }
            current=current->right;
        }

        
    }
};
*/

