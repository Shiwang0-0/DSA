// Given a linked list of 0s, 1s and 2s, sort it.

// APPROACH 1  T.C: O(N) S.C: O(1)
// Change data
// class Solution
// {
//     public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node* segregate(Node *head) {
//         int zero=0,one=0,two=0;
//         Node* ptr=head;
//         // Add code here
//         while(ptr)
//         {
//             if(ptr->data==0)   
//                 zero++;
//             else if(ptr->data==1)
//                 one++;
//             else if(ptr->data==2)
//                 two++;
                
//             ptr=ptr->next;
//         }
//         ptr=head;
//         while(ptr)
//         {
//             if(zero)
//             {
//                 ptr->data=0;
//                 zero--;
//             }
//             else if(one)
//             {
//                 ptr->data=1;
//                 one--;
//             }
//             else if(two)
//             {
//                 ptr->data=2;
//                 two--;
//             }
            
//             ptr=ptr->next;    
//         }
        
//         return head;
//     }
// };



// APPROACH 2  T.C: O(N) S.C: O(1)
// Change links

// class Solution
// {
//     public:
    
//     void insert(Node * ptr,Node * &zeroTail)
//     {
//         zeroTail->next=ptr;
//         zeroTail=ptr;
//     }
    
//     Node* segregate(Node *head) { 
//         // Dummy head nodes
//         Node* zeroHead=new Node(-1); 
//         Node* oneHead=new Node(-1); 
//         Node* twoHead=new Node(-1); 
        
//         Node* zeroTail=zeroHead;
//         Node* oneTail=oneHead;
//         Node* twoTail=twoHead;
        
//         Node* ptr=head;
//         while(ptr)
//         {
//             if(ptr->data==0)
//             {
//                 insert(ptr,zeroTail);
//             }
//             else if(ptr->data==1)
//             {
//                 insert(ptr,oneTail);
//             }
//             else if(ptr->data==2)
//             {
//                 insert(ptr,twoTail);
//             }
//             ptr=ptr->next;
//         }
        
//         if(oneHead->next)
//             zeroTail->next=oneHead->next;
        
//         else
//             zeroTail->next=twoHead->next;
           
           
//         oneTail->next=twoHead->next;
        
//         twoTail->next=NULL;
//         head=zeroHead->next;
        
//         delete(zeroHead);
//         delete(oneHead);
//         delete(twoHead);
        
//         return head;
//     }
// };