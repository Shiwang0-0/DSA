
// // Intersection of two linked list in O(1) space and O(n+m) time

// class Solution {
// public:

//     int len(ListNode *head)
//     {
//         int i=0;
//         while(head!=NULL)
//         {
//             i++;
//             head=head->next;
//         }
//         return i;
//     }

//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

//         int lenA=len(headA);
//         int lenB=len(headB);

//         if(lenA>lenB)
//         {
//             while(lenA>lenB)
//             {
//                 headA=headA->next;
//                 lenA--;
//             }
//         }
//         else if(lenA<lenB)
//         {
//             while(lenA<lenB)
//             {
//                 headB=headB->next;
//                 lenB--;
//             }
//         }

//         while(headA && headB)
//         {
//             if(headA==headB)
//             {
//                 return headA;
//             }
//             headA=headA->next;
//             headB=headB->next;
//         }

//         return NULL;
//     }
// };