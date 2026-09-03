#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node* root)
{
    int data;
    cout<<"enter data: "<<endl;
    cin>>data;
    root = new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"enter data for left node: "<<endl;
    root->left=createTree(root);
    cout<<"enter data for right node: "<<endl;
    root->right=createTree(root);
    return root;
}


node* BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        // to have sperator in levels
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }    
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return root;
}

node* createFromLevelOrderTraversal(node* root)
{
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    queue<node*>q;
    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        int leftData;
        cout<<"Enter left node for "<<temp->data <<endl;
        cin>>leftData;
        if(leftData!=-1)
        {
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter right node for "<<temp->data <<endl;
        cin>>rightData;
        if(rightData!=-1)
        {
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }

    return root;
}


int main()
{
    node* root=NULL;

    root=createTree(root);  //Flow goes like root->left->left->left----

    // root=createFromLevelOrderTraversal(root); //Flow goes like root->left->right-----
    
    root=BFS(root);

    return 0;
}


// 5 3 6 -1 -1 1 -1 -1 4 3 -1 5 -1 -1 7 -1 -1

// 1 3 7 -1 -1 -1 5 11 -1 -1 17 -1 -1