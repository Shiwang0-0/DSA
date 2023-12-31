// Merge Nodes in Between Zeros
// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation: 
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.


//Apporach 1    T.C: O(N^2)   S.C: O(N)

// class Solution {
// public:

    // ListNode* insert(ListNode* newHead,int sum)
    // {
    //     ListNode* head=newHead;
    //     ListNode* newNode= new ListNode();
    //     newNode->val=sum;
    //     newNode->next=NULL;
    //     if(head==NULL)
    //     {
    //         newHead=newNode;
    //         return newHead;
    //     }
    //     while(head->next!=NULL)
    //     {
    //         head=head->next;
    //     }
    //     head->next=newNode;
    //     return newHead;
    // }

    // ListNode* mergeNodes(ListNode* head) {
    //     int sum=0;
    //     ListNode* newHead=NULL;
    //     while(head && head->next)
    //     {
    //         sum=0;
    //         head=head->next;
    //         while(head->val!=0)
    //         {
    //             sum=sum+head->val;
    //             head=head->next;
    //         }
    //         newHead=insert(newHead,sum);
    //     }
    //     return newHead;
    // }
   
// };



// Apporach 2  T.C: O(N)  S.c: O(N)


// class Solution {
// public:

//     ListNode* mergeNodes(ListNode* head) {
//         if(head->next==NULL)
//         return NULL;
//         int sum=0;
//         ListNode* ptr=head->next;
//             while(ptr && ptr->val!=0 )
//             {
//                 sum=sum+ptr->val;
//                 ptr=ptr->next;
//             }
//         head->val=sum;
//         head->next=mergeNodes(ptr);
//     return head;
//     }
// };




// Approach 3  T.C: O(N)  S.C: O(1)


// class Solution {
// public:
// ListNode* mergeNodes(ListNode* head) {
//         head=head->next;
//         ListNode* itr=head;
//         ListNode* newHead=head;
//         int sum=0;
//         while(itr){
//             if(itr->val!=0)
//             {
//                 sum=sum+itr->val;
//                 itr=itr->next;
//             }
//             else
//             {
//                 newHead->val=sum;
//                 itr=itr->next;
//                 newHead->next=itr;
//                 newHead=itr;
//                 sum=0;
//             }
//         }
//     return head;
// }
// };