
/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// APPROACH 1   T.C: O(N)  S.C: O(N)  (WITH MAP)

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
        {
            return NULL;
        }

        Node* ptr=head;
        Node* newHead=NULL;
        Node* newTail=NULL;
        
        // making linkedlist using only next pointer
        if(ptr)
        {
            Node* newNode = new Node(ptr->val); 
            newHead=newNode;
        }

       
        Node* newPtr=newHead;
        ptr=ptr->next;

        while(ptr)
        {
            Node* newNode = new Node(ptr->val);
            newNode->next=NULL;
            newPtr->next=newNode;
            newPtr=newNode;
            ptr=ptr->next;
        }
        
        //

        ptr=head;
        newPtr=newHead;

        // create mapping of original and cloned linkedlist.
        unordered_map<Node*,Node*>mp;

        while(newPtr && ptr)
        {
            mp[ptr]=newPtr;
            ptr=ptr->next;
            newPtr=newPtr->next;
        }

        newPtr=newHead;
        ptr=head;

        //find which original cloned node is mapped to which cloned node (they will be mapped to their duplicates only) and then the original's random is what we needed to be pointed by cloned random.

        while(newPtr && ptr)
        {
            if(ptr->random)
                newPtr->random = mp[ptr->random];
            else
                newPtr->random =NULL;

            newPtr=newPtr->next;
            ptr=ptr->next;
        }

    return newHead;
    }
};





APPROACH 2  T.C: O(N)  S.C: O(1) (WITHOUT MAP)

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
        {
            return NULL;
        }

        Node* ptr=head;

        // Creating a clone linkedlist with next pointer only.
        Node* newHead=new Node(ptr->val);
        Node* newPtr=newHead;
        ptr=ptr->next;
        while(ptr)
        {
            Node* newNode=new Node(ptr->val);
            newPtr->next=newNode;
            newPtr=newNode;
            ptr=ptr->next;
        }
        newPtr->next=NULL;

        ptr=head;
        newPtr=newHead;
        //changing links of original and cloned linkedlist and making a zig-zag pattern

        Node* ahead=ptr;
        Node* newAhead=newPtr;

        while(ptr && newPtr)
        {
            ahead=ahead->next;    
            newAhead=newAhead->next; 
            ptr->next=newPtr;
            newPtr->next=ahead;
            ptr=ahead;
            newPtr=newAhead; 
        }
        
        ptr=head;
        newPtr=newHead;

        // marking random of cloned list using original list
        while(ptr && newPtr)
        {
            if(ptr->random)
                newPtr->random=ptr->random->next;
            else
                newPtr->random=NULL;

            ptr=newPtr->next;
            if(ptr)
                newPtr=ptr->next;
            else
                newPtr=NULL;
        }

        ptr=head;
        newPtr=newHead;

        // undoing the zig-zag's made 
        ahead=head;
        newAhead=newHead;
        
        while(ptr && newPtr)
        {
            ahead=newPtr->next;
            if(ahead)
                newAhead=ahead->next;
            else 
                newAhead=NULL;
                
            ptr->next=ahead;
            newPtr->next=newAhead;
            ptr=ahead;
            newPtr=newAhead;    
        }

    return newHead;
    }
};


*/