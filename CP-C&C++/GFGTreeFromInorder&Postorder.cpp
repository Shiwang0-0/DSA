// given two array post and in order and their size


// Node* func(int in[],int post[],int &index,  int s, int e,int n)
//     {
//         if(s>e || index<0 )
//             return NULL;
            
//         int pos=-1;
        
        
//         int element=post[index--];
        
//         for(int i=s;i<=e;i++)
//         {
//             if(element==in[i])
//             {
//                 pos=i;
//                 break;
//             }
                
//         }
//         Node* root=new Node(element);  // dont do in[pos] although both are same but if element not found then pos=-1 which is not a index in the array.
//         root->right=func(in,post,index,pos+1,e,n); 
//         root->left=func(in,post,index,s,pos-1,n);
        
        
//         return root;
//     }
    
// Node *buildTree(int in[], int post[], int n) {
//     // Your code here
//         int s=0;
//         int index=n-1;
//         int e=n-1;
        
//         Node* root=func(in,post,index,s,e,n);
        
//         return root;
// }