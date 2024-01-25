// given two array pre and in order and their size

// class Solution{
//     public:
    
//     Node* func(int in[],int pre[],int &index,  int s, int e,int n)
//     {
//         if(s>e || index>=n)
//             return NULL;
            
//         int pos=-1;
        
        
//         int element=pre[index++];
        
//         for(int i=s;i<=e;i++)
//         {
//             if(element==in[i])
//             {
//                 pos=i;
//                 break;
//             }
                
//         }
//         Node* root=new Node(element);  // dont do in[pos] although both are same but if element not found then pos=-1 which is not a index in the array.
//         root->left=func(in,pre,index,s,pos-1,n);
//         root->right=func(in,pre,index,pos+1,e,n);
        
//         return root;
//     }
    
//     Node* buildTree(int in[],int pre[], int n)
//     {
//         // Code here
        
//         int s=0;
//         int index=0;
//         int e=n-1;
        
//         Node* root=func(in,pre,index,s,e,n);
        
//         return root;
        
//     }
// };