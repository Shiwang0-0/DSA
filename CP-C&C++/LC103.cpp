
// Binary Tree Zigzag Level Order Traversal

// class Solution {
// public:

//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(root==NULL)
//         {
//             return {};
//         }
//         queue<TreeNode*>q;
//         vector<vector<int>>ans; 
//         vector<int>v;
//         q.push(root);
//         bool leftToRight=true;
//         int qSize;
//         TreeNode* temp;
//         while(!q.empty())
//         {
//            v.clear();
//             qSize=q.size();
//             while(qSize)
//             {
//                 temp=q.front();
//                 v.push_back(temp->val);
//                 q.pop();
//                     if(temp->left)
//                     {
//                         q.push(temp->left);
//                     }
//                     if(temp->right)
//                     {
//                         q.push(temp->right);
//                     }
//                 qSize--;        
//             }
//             if(!leftToRight)
//             {
//                 reverse(v.begin(),v.end());
//             }
//             ans.push_back(v);
//             leftToRight=!leftToRight;
//         }
        
//         return ans;
//     }
// };