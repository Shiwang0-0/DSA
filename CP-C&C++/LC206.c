/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* current=head;
        struct ListNode* prev=NULL;
        struct ListNode* forward=head;
  while(current!=NULL)
  {
    forward=current->nxt;
    current->nxt=prev;
    prev=current;
    current=forward;
    // printf("yaha?");
  }
  head=prev;
    }
};