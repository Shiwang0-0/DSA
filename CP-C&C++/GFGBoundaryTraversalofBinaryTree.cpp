class Solution {

private:
    void forLeft(Node* root, vector <int> &ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL) )
        {
            return ;
        }
        ans.push_back(root->data);  
        if(root->left)
        {
            forLeft(root->left,ans);
        }
        else
        {
            forLeft(root->right,ans);
        }
        
    }
    
    void forRight(Node* root, vector <int> &ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL) )
        {
            return ;
        }
          
        if(root->right)
        {
            forRight(root->right,ans);
        }
        else
        {
            forRight(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    void traverseLeaf(Node* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    
    
public:
    vector <int> boundary(Node *root)
    {
        vector <int> ans;
        if(root==NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        forLeft(root->left,ans);
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
        forRight(root->right,ans);
        
        return ans;
    }
};