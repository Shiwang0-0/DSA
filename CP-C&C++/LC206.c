//reverse a singly linkedlist


//iterative apporach
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


//recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }
};