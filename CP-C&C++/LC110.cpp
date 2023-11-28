
// Determine whether the tree is a balanced tree or not.
//A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.


// class Solution {
// public:

//     int height(TreeNode* root)
//     {
//         if(root==NULL)
//         return 0;

//         int left=height(root->left);
//         int right=height(root->right);

//         int ans=max(left,right)+1;
//         return ans;
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)
//         return 1;

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);

//         int heightLeft=height(root->left);  
//         int heightRight=height(root->right);

//         if(abs(heightLeft-heightRight) >=2)
//         {
//             return 0;
//         } 
//         else
//         {
//             if(right && left)
//             {
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//     }
// };




// OPTMIZED SOLUTION

// class Solution {
// public:

//     pair<bool,int> isBal(TreeNode* root)
//     {
//         if(root==NULL)
//             {
//                 pair<bool,int> p = make_pair(true,0);
//                 return p;
//             }
            
//             pair<bool,int> left=isBal(root->left);
//             pair<bool,int> right=isBal(root->right);
            
//             bool leftAns=left.first;
//             bool rightAns=right.first;
            
//             bool diff=abs(left.second-right.second)<=1;
            
//             pair<bool,int>ans;
//             ans.second=max(left.second,right.second)+1;
            
//             if(diff && leftAns && rightAns)
//             {
//                 ans.first=true;
//             }
//             else
//             {
//                 ans.first=false;
//             }
//             return ans;
//     }

//     bool isBalanced(TreeNode* root)
//     {  
//         return isBal(root).first;
//     }
// };