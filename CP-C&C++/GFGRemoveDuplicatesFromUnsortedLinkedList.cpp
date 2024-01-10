

// APPROACH-1  T.C: O(N^2)  S.C: O(1)

// class Solution
// {
//     public:
    //Function to remove duplicates from unsorted linked list.
    // Node * removeDuplicates( Node *head) 
    // {
    //  Node* current=head;
    //  while(current)
    //  {
    //      Node *ptr=current;
    //      while(ptr && ptr->next)
    //      {
    //          if(current->data==ptr->next->data)
    //          {
    //              Node* temp=ptr->next;
    //              ptr->next=temp->next;
    //              free(temp);
    //          }
    //          else
    //          {
    //              ptr=ptr->next;
    //          }
                
    //      }
    //      current=current->next;
    //  }
    //  return head;
     
    // }
// };    





// APPROACH-2  T.C: O(N)  S.C: O(N)

// class Solution
// {
//    public:
//     Node * removeDuplicates( Node *head) 
//     {
//      unordered_map<int,bool>visited;
//      Node *current=head;
//      Node *prev=NULL;
//      while(current)
//      {
//          if(visited[current->data]==true)
//          {
//              Node* temp=current;
//              current=current->next;
//              prev->next=current;
//              free(temp);
//          }
//          else
//          {
//              visited[current->data]=true;
//              prev=current;
//              current=current->next;
//          }
            
//      }
//      return head;
//     }
// };