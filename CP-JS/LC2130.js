//Maximum Twin Sum of a Linked List
//Approach:

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
    let slow=head,forward,prev;
    let fast=head;
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
    let max=0;
    let sum;
    while(slow)
    {
        sum=slow.val+fast.val;
        if(sum>max)
        {
            max=sum;
        }
        slow=slow.next;
        fast=fast.next;
    }
    return max;
};