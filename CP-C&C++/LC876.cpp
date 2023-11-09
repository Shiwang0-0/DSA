//Find middle of the linkedlist

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while(fast!=NULL)
        // {
        //     slow=slow->next;
        //     fast=fast->next;
        //     if(fast)
        //     {
        //         fast=fast->next;
        //     }
        // }
        // return slow;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};