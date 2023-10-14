//User function Template for javascript

/**
 * @param {Node} head
 * @returns {Node}
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {
    //Function to reverse a linked list.
    reverseList(head)
    {
        let current =head;
        let prev=null;
        let forward=null;
        while(current)
        {
            forward=current.next;
            current.next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
    
}