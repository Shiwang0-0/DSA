/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let fast=head,forward,prev;
    let slow=head;
    while(fast && fast.next)
    {
        slow=slow.next;
        fast=fast.next.next;
    }
    prev=slow;
    slow=slow.next;
    prev.next=null;
    while(slow)
    {
        forward=slow.next;
        slow.next=prev;
        prev=slow;
        slow=forward;
    }
    fast=head;
    slow=prev;
    while(slow)
    {
        if(slow.val!==fast.val)
        {
            return false;
        }
        else
        {
            slow=slow.next;
            fast=fast.next;
        }
    }
    return true;
    
};