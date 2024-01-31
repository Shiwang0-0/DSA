// Convert Sorted List to Binary Search Tree


// class Solution {
// public:

//     int countNode(ListNode* head)
//     {
//         int n=0;
//         while(head)
//         {
//             n++;
//             head=head->next;
//         }
//         return n;
//     }

//     ListNode* findMid(ListNode* head,int mid)
//     {
//         int i=0;
//         while(i<mid && head->next)
//         {
//             head=head->next;
//             i++;
//         }
//         return head;
//     }   

//     TreeNode* makeBST(ListNode* &head,int n)
//     {
        
//         if(n<=0 || head==NULL)
//             return NULL;
        
//         ListNode* temp= findMid(head,n/2);
        
//         TreeNode* root= new TreeNode(temp->val);

//         root->left=makeBST(head,(n/2));

//         head=head->next;
//         root->right=makeBST(head,n-(n/2)-1);
//         return root;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         if(head==NULL)
//             return NULL;
        
//         int n=countNode(head);

//         return makeBST(head,n);
        
//     }
// };