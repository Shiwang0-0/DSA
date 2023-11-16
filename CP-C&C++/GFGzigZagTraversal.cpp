class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> result;
    	if(root==NULL)
    	{
    	    return result;
    	}
    	
    	queue< Node* >q;
    	q.push(root);
    	
    	bool leftToRight=true;
    	
    	while(!q.empty())
    	{
    	    Node* root=q.front();
    	    int size=q.size();
    	    vector <int> ans(size);
    	    
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* frontNode=q.front();
    	        q.pop();
    	        int whichSide=leftToRight ? i : size-i-1;
    	        
    	        ans[whichSide]=frontNode->data;
    	        
    	        if(frontNode->left)
    	        {
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right)
    	        {
    	            q.push(frontNode->right);
    	        }
    	    }
    	    leftToRight=!leftToRight;
    	    
    	   for(int j=0;j<ans.size();j++)
    	   {
    	       result.push_back(ans[j]);
    	   }
    	}
        return result;
    }
};