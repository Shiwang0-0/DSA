// // PRE ORDER 

// class Solution{
//     public:
//     vector<int> preOrder(Node* root)
//     {
//         vector<int>ans;
//         stack< Node* >s;
//         s.push(root);
//         while(!s.empty())
//         {
//             Node* temp=s.top();
//             s.pop();
//             ans.push_back(temp->data);
//             if(temp->right)
//             {
//                 s.push(temp->right);
//             }
//             if(temp->left)
//             {
//                 s.push(temp->left);
//             }
            
//         }
//     return ans;
//     }
// };




// // IN ORDER

// class Solution {
// public:
//     vector<int> inOrder(Node* root)
//     {
//         vector<int>ans;
//         stack <Node*> s;
        
//         while(!s.empty() || root!=NULL)
        
//         {
//             while(root!=NULL)
//             {
//                 s.push(root);
//                 root=root->left;
//             }
//             root=s.top();
            
//             ans.push_back(root->data);
//             s.pop();
            
//             root=root->right;
//         }
        
//         return ans;
//     }
// };



// // POST ORDER

// class Solution{
//     public:
//     vector<int> postOrder(Node* root) {
//         vector<int>ans;
//         stack< Node* >s;
//         s.push(root);

//             while(!s.empty())
//             {
//                Node* topper=s.top();
//                s.pop();
//                ans.push_back(topper->data);
//                if(topper->left)
//                {
//                    s.push(topper->left);
//                }
//                if(topper->right)
//                {
//                    s.push(topper->right);
//                }
               
                
//             }
//             reverse(ans.begin(),ans.end());
//     return ans;
//     }
// };