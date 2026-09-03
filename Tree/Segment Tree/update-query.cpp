#include<iostream>
#include<vector>
using namespace std;

vector<int>tree;

// demonstrating range sum query


void updateQuery(int target,int value,vector<int>&v,int idx,int l,int r){
    if(l==r){ // we are sure it will lead to the current target index only
              // since recusrion happens based on the target<=mid if else condition
              // we dont need to explicity find where are target is in the segment array

              // dont do idx==target
              // because idx is of segment tree, target is of given array

        tree[idx]=value;
        return;
    }
    int mid=(l+r)/2;
    if(target<=mid){ // the target index is present in left child
        updateQuery(target,value,v,2*idx+1,l,mid);
    }
    else{
        updateQuery(target,value,v,2*idx+2,mid+1,r);
    }
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    return;
}

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
    cout<<endl;

    int target,value;
    cout<<"update index ";
    cin>>target;
    cout<<" as value ";
    cin>>value;

    updateQuery(target,value,v,0,l,r); // give whole tree here also

    for(auto it:tree)
        cout<<it<<" ";
    cout<<endl;
    
    return 0;
}