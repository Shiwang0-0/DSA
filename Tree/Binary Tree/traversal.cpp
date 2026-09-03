#include <iostream>
#include<queue>
#include<stack>
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

// void preorder(node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     cout<< root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
//     return;
// }

// void inorder(node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout<< root->data<<" ";
//     inorder(root->right);
//     return;
// }

// void postorder(node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout<< root->data<<" ";
//     return;
// }

void iterpreorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* root=q.top();
        printf("%d",root->data);
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
}


void zigZag (struct node* root)
{
    if(root==NULL)
            return;
    
        queue<struct node*>q;
        q.push(root);
        q.push(NULL);
        bool leftToRight=0;
        while(!q.empty())
        {
            struct node* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                leftToRight=!leftToRight;
            }
            else{
                printf("%d",temp->data);
                if(leftToRight)
                {
                    if(temp->right)
                        q.push(temp->right);
                    if(temp->left)
                        q.push(root->left);
                }
                else
                {
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right); 
                }
            }
            
        }
}



int main()
{
    node* root=NULL;
    root=createTree(root);

    // cout<<"Preorder: ";
    // iterpreorder(root);
    // cout<<endl<<"Inorder: ";
    // iterinorder(root);
    // cout<<endl<<"PostOrder: ";
    // iterpostorder(root);
    cout<<endl<<"zigZag: ";
    zigZag(root);

    return 0;
}


// 5 3 -1 1 -1 -1 4 3 -1 5 -1 -1 -1

// 1 3 7 -1 -1 -1 5 11 -1 -1 17 -1 -1