//reverse doubly linkedlist (using recursion)

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head==NULL || head->next==NULL)
        {
            head->prev=NULL;
            return head;
        }
        
        Node* node=reverseDLL(head->next); 
        head->prev=head->next;
        head->next->next=head;
        head->next=NULL;
        return node;
    }
};