// Split Linked List in Parts

// class Solution {
// public:

//     int countNodes(ListNode* head)
//     {
//         int c=0;
//         while(head)
//         {
//             c++;
//             head=head->next;
//         }
//         return c;
//     }

//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         int n=countNodes(head);
//         int subSize=n/k;
//         int leftOvers=n%k;  // will be definatley less than k.

//         vector<ListNode*>ans(k);  // give the size so that the rest are filled with NULL
//         ListNode* prev=NULL;
//         for(int i=0;i<k;i++)
//         {
//             ans[i]=head;
//             for(int j=0;j<subSize+(leftOvers>0) && head;j++)
//             {
//                 prev=head;
//                 head=head->next;
//             }
//             if(prev)
//                 prev->next=NULL;
//             leftOvers--;
//         }
//         return ans;
//     }
// };