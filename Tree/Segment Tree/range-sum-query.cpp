#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll>tree;

void buildTree(vector<ll>&v,int idx,int l,int r){
    if(l==r){
        tree[idx]=v[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(v,2*idx+1,l,mid); // left child
    buildTree(v,2*idx+2,mid+1,r); // right child
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

ll findRangeSum(int idx,int l,int r,int a,int b){
    // a and b is the range we want to find the sum of
    // l and r is the range of how the segment tree is divided

    if(b<l || a>r) // out of range
        return 0;
    if(a<=l && b>=r) // whole a-b lies within the current node
        return tree[idx]; // get value from the segment tree
    
    // otherwise the range overlaps
    // get the answer from both the subtrees
    int mid=(l+r)/2;
    ll val1=findRangeSum(2*idx+1,l,mid,a,b);
    ll val2=findRangeSum(2*idx+2,mid+1,r,a,b);
    return val1+val2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    tree.resize(4*n,-1);
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    buildTree(v,0,0,n-1);

    // for(auto it:tree)
    //     cout<<it<<" ";

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<findRangeSum(0,0,n-1,a-1,b-1)<<endl;
    }

return 0;
}