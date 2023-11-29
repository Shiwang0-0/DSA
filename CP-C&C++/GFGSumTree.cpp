// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


// class Solution
// {
//     public:
//     pair<bool,int> isSumTreeFast(Node* root)
//     {
//          // Your code here
         
//          if(root==NULL)
//          {
//              pair<bool,int>p=make_pair(true,0);
//              return p;
//          }
//          if(root->right==NULL && root->left==NULL)
//          {
//              pair<bool,int>ans=make_pair(true,root->data);
//              return ans;
//          }
//          pair<bool,int>left=isSumTreeFast(root->left);
//          pair<bool,int>right=isSumTreeFast(root->right);
//          pair<bool,int>result;
//          if(left.first && right.first && (left.second + right.second)==root->data)
//          {
//              result.first=true;
//              result.second=root->data+left.second+right.second;
//              return result;
//          }
//          else
//          {
//              pair<bool,int>result=make_pair(false,root->data);
//              return result;
//          }
         
//     }
//     bool isSumTree(Node* root)
//     {
//         return isSumTreeFast(root).first;
//     }
// };