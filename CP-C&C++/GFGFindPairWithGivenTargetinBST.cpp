// Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 


// class Solution{
//   public:
//     // root : the root Node of the given BST
//     // target : the target sum
//     void inorder(struct Node* root,int target,vector<int>&v)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
//         inorder(root->left,target,v);
//         v.push_back(root->data);
//         inorder(root->right,target,v);
//     }
    
    
//     int isPairPresent(struct Node *root, int target)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         vector<int>v;
//         inorder(root,target,v);

//         int size=v.size();
//         int start=0;
//         int end=size-1;
//         //  while(v[start]<v[end])
//         while(start<end)
//         {
//             if((v[start]+v[end]) == target)
//             {
//                 return true;
//             }
//             if((v[start]+v[end]) > target)
//             {
//                 end--;
//             }
//             if((v[start]+v[end]) < target)
//             {
//                 start++;
//             }
//         }
//         return false;
        
//     }
// };