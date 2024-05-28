// Identify whether the two trees are identical or not.

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL && q==NULL){
//             return 1;
//         }
//         if((p==NULL && q!=NULL) || (q==NULL && p!=NULL)){
//             return 0;
//         }

//         if(p->val!=q->val){
//             return 0;
//         }
        
//         int left=isSameTree(p->left,q->left);
//         int right=isSameTree(p->right,q->right);


//         if(left && right)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }

//     }
// };
