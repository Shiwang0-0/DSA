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

int main()
{
    node* root=NULL;
    root=createTree(root);
    
    return 0;
}


// 5 3 -1 1 -1 -1 4 3 -1 5 -1 -1 -1

// 1 3 7 -1 -1 -1 5 11 -1 -1 17 -1 -1