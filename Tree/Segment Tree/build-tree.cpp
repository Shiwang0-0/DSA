#include<iostream>
#include<vector>
using namespace std;

vector<int>tree;

// demonstrating sum query

void buildTree(vector<int>&v,int idx,int l,int r){ // idx represent index in the tree array
    if(l==r){
        tree[idx]=v[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(v,2*idx+1,l,mid); // left child
    buildTree(v,2*idx+2,mid+1,r); // right child
    tree[idx]=tree[2*idx+1]+tree[2*idx+2]; // accumulate both childs, sum
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    tree.resize(2*n,-1);
    int l=0,r=n-1;
    buildTree(v,0,l,r);

    for(auto it:tree)
        cout<<it<<" ";
    return 0;
}