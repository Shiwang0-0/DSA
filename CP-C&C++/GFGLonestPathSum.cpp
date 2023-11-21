//complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.


class Solution
{
private:
    pair <int,int> ans(Node* root)
    {
        if(root==NULL)
        {
            return make_pair(0,0);
        }
        
        pair<int,int> l=ans(root->left);
        pair<int,int> r=ans(root->right);
        
        if(l.first>r.first)
        {
            return make_pair(l.first+1,l.second+root->data);
        }
        else if(l.first==r.first)
        {
            if(l.second>r.second)
            {
                return make_pair(l.first+1,l.second+root->data);
            }
            else
            {
                return make_pair(r.first+1,r.second+root->data);
            }
        }
        else{
            return make_pair(r.first+1,r.second+root->data);
        }
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        return ans(root).second;
    }
};