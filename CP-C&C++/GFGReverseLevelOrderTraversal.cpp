//using Queue,revese level order travesal is performed (first pushing the right node and then left is the keypoint)


vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
     queue <Node *> q;
     q.push(root);
     
     
     while(!q.empty())
     {
         root=q.front();
         ans.push_back(root->data);
         q.pop();
         if(root->right)
         {
             q.push(root->right);
         }
          if(root->left)
         {
             q.push(root->left);
         }
     }
     (reverse(ans.begin(), ans.end()));
     return ans;
}