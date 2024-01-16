
// Print all the paths from Root to leaf exist in a Tree

/* 
 send temp without reference because with every 
recursive call it will be tempered and it need to be tempered 
,it will need a copy for every recursive call so that 
the previous elements can be easily retrived when the particular call returns. 

void solve(Node* root, vector<vector<int>>&v,vector<int>temp)
{
    if(root==NULL)
    {
        return;
    }
    if(root->right || root->left)
        temp.push_back(root->data);
        
    else if(!root->right && !root->left){
        temp.push_back(root->data);  // if both left and right are NULL atleast send their parent.
        v.push_back(temp);
        return;
    }
    
    solve(root->left,v,temp);
    
    solve(root->right,v,temp);
    
    return;
}

vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>>v;
    vector<int>temp;
    if(root==NULL)
        return v;
    
    solve(root,v,temp);
    return v;
}

*/