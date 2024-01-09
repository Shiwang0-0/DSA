// Reverse Nodes in k-Group



// class Solution {
// public:
//     ListNode* solve(ListNode* head, int k)
//     {
//         if(head==NULL)
//         {
//             return NULL;
//         }
        
//         ListNode* prev=NULL;
//         ListNode* forward=head;
//         ListNode* current=head;

//         int i=0;

//         ListNode* temp=current;
//         for(i=0;i<k && temp;i++)
//         {
//             temp=temp->next;
//         }
//         if(i<k)  // remaining size is less than the number of nodes to be reversed so return their head without reversing.
//         {
//             return head;
//         }
        
//         // else if size is sufficient then reverse the portion.
//         i=0;
//         while(current && i<k)
//         {
//             forward=current->next;
//             current->next=prev;
//             prev=current;
//             current=forward;   
//             i++;
//         }
        
//         if(forward)
//         head->next=solve(forward,k);
        
//         return prev;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         return solve(head,k);
//     }
// };