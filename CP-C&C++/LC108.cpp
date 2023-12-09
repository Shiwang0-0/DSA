
// //Convert Sorted Array to Binary Search Tree

// class Solution {
// public:

//     TreeNode* makeTree(int l, int r, vector<int>& nums)
//     {
//         if(l>r)
//         {
//             return NULL;
//         }
//         int mid=(l+r)/2;
//         TreeNode* newNode= new TreeNode();
//         newNode->val=nums[mid];
//         newNode->left=makeTree(l,mid-1,nums);
//         newNode->right=makeTree(mid+1,r,nums);
//         return newNode;
//     }

//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int size=nums.size();
//         return makeTree(0,size-1,nums);
//     }
// };