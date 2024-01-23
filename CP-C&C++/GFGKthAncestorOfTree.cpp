

// Kth ancestor of tree

// bool func(Node *root, int &k, int node, int &limit, int &ans)
// {
//     if(root==NULL)
//         return 0;
    
//     if(root->data==node)
//         return 1;
    
//     bool l= func(root->left,k,node,limit,ans);
//     bool r= func(root->right,k,node,limit,ans);
    
//     if(l || r)
//         k--;
        
//     if(k==0)
//     {
//         ans=root->data;
//         k=INT_MAX;  // for other calls if anyhow l=0,r=0 and k is also 0 it doesnt change our ans.
//         limit=1;  //denoting element's ancestor is within the tree
//     }
        
        
//     return (l||r);
// }

// int kthAncestor(Node *root, int k, int node)
// {
//     // Code here
//     int limit=0,ans=0;
//     bool val=func(root,k,node,limit,ans);
    
//     if(limit!=1)  // the tree gets finished before the number of ancestors it could find.
//         return -1;
    
//     return ans;

    
