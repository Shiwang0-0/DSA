
// Combination of floyed's algorithm and then moving slow(from head) and fast(from intersection of slow and fast) at a same pace.

// class Solution
// {
//     public:
//      //Function to find first node if the linked list has a loop.
//     int findFirstNode(Node* head)
//     {
//         // your code here
//         Node* slow=head;
//         Node* fast=head;
//         bool isLoop=false;
//         while(fast!=NULL && fast->next!=NULL)
//         {
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==slow)
//             {
//                 isLoop=true;
//                 break;
//             }
//         }
//         if(isLoop)
//         {
//             slow=head;
//             while(slow!=fast)
//             {
//                 slow=slow->next;
//                 fast=fast->next;
//             }
//             return fast->data;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// };