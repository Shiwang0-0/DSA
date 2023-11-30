//Binary Tree Right Side View


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<int>ans;
//     vector<int> view(TreeNode* root,int level)
//     {
//         if(root==NULL)
//         {
//             return ans;
//         }
//         if(level==ans.size())
//         {
//             ans.push_back(root->val);
//         }
//         // ans.push_back(root->val);
//         view(root->right,level+1);
//         view(root->left,level+1);

//         return ans;
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         int level=0;
//         return view(root,level);
//     }
// };






//  class Solution {
// public:
//     vector<int>ans;
//     vector<int> rightSideView(TreeNode* root) {
//         if(root==NULL)
//         {
//             return ans;
//         }

//         queue<TreeNode*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int i=0;
//             int size=q.size();

//             while(i<size)
//             {
//                 TreeNode* temp=q.front();
//                 q.pop();
//                 if(i==size-1)
//                 {
//                     ans.push_back(temp->val);
//                 }
//                 if(temp->left !=NULL)
//                 {
//                     q.push(temp->left);
//                 }
//                 if(temp->right !=NULL)
//                 {
//                     q.push(temp->right);
//                 }
//                 i++;
//             }
//         }
//         return (ans);
//     }
// };