// Maximum Level Sum of a Binary Tree

// Key Point: Insure that if vector is full or empty its size gets increased by push backing in the element,
//            Insure that if the index already exist then no need to push back just add the value to the desired(pre-existing) index


// class Solution {
// public:

//     void findLevelSum(TreeNode* root,vector<int> &sums,int i)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
//         if (i == sums.size()) {
//         sums.push_back(root->val);    //To insure that if vector is full or empty its size gets increased by push backing in the element
//         }
//         else
//         {
//             sums[i]=sums[i]+root->val;   //To insure that if the index already exist then no need to push back just add the value to the desired(pre-existing) index
//         }
//         if(root->left)
//         {
//             findLevelSum(root->left,sums,i+1);
//         }
//         if(root->right)
//         {
//             findLevelSum(root->right,sums,i+1);
//         }
//     }

//     int searchElement(vector<int> sums,int maxElement)
//     {
//         for(int i=0;i<sums.size();i++)
//         {
//             if(maxElement==sums[i])
//             {
//                 return i;
//             }
//         }
//         return 0;
//     }

//     int maxLevelSum(TreeNode* root) {
//         vector<int> sums;
//         findLevelSum(root,sums,0);
//         int maxElement = *max_element(sums.begin(), sums.end());
//         return searchElement(sums,maxElement)+1;
//     }
// };