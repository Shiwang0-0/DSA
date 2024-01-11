
// Merge Two Sorted Lists

// class Solution {
// public:

//     ListNode* solve(ListNode* head, ListNode* other)
//     {

//         ListNode* temp1=head;
//         ListNode* temp2=other;
//         ListNode* store=NULL;

//         while(temp1->next && temp2)
//         {
//             if(temp1->val <= temp2->val  && temp1->next->val > temp2->val)
//             {
//                 store=temp2->next;
//                 temp2->next=temp1->next;
//                 temp1->next=temp2;
//                 temp1=temp2;
//                 temp2=store;
//             }
//             else
//             {
//                 temp1=temp1->next;
//             }     
//         }
//         if(temp2)
//         {
//             temp1->next=temp2;
//         }
//         return head;
//     }

//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1)
//             return list2;
//         if(!list2)
//             return list1;


//         ListNode* head=NULL;

//         if(list1->val <= list2->val)
//             head=solve(list1,list2);

//         else
//             head=solve(list2,list1);

//         return head;
//     }
// };