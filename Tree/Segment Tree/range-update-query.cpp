#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<ll>tree;
vector<ll>lazy;

void buildTree(vector<ll>&v,int idx,int l,int r){
    if(l==r){
        tree[idx]=v[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(v,2*idx+1,l,mid);
    buildTree(v,2*idx+2,mid+1,r);
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

void rangeUpdate(int idx,int l,int r,int a,int b,ll u){

    if(lazy[idx]!=0LL){ // check if this node has be left with some future value to propogate
        int childs=(r-l+1);
        tree[idx]+=(childs*lazy[idx]); // to update with the previous visit value (if there were assigned some value)

        if(l!=r){ // if it is not a leaf node, than only curr node will have childs
            lazy[2*idx+1]+=lazy[idx]; // propogate the previous lazy value to the child nodes, so that they can be updated, when visited again
            lazy[2*idx+2]+=lazy[idx]; //                                    like we do here   <------
            //                                                                                      |
            // on previous visit this was left by lazy, now since we are on the node, utilize it ----
        }
        lazy[idx]=0LL;
    }

    if(b<l || a>r) // out of range
        return;

    if(a<=l && b>=r){ // the current node lies in the target range 
        int childs=(r-l+1);
        tree[idx]+=(childs*u); // to update with the new value 
        
        if(l!=r){ // leaf doesnt have childs
            lazy[2*idx+1]+=u; // propogate the new changed values
            lazy[2*idx+2]+=u;
        }
        return; // lazy propogate
    }

    // overlapping range
    int mid=(l+r)/2;

    rangeUpdate(2*idx+1,l,mid,a,b,u);
    rangeUpdate(2*idx+2,mid+1,r,a,b,u);
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

ll findValue(int idx,int l,int r,int k){

    if(lazy[idx]!=0LL){ // update pending lazy values
        int childs=r-l+1;
        tree[idx]+=(childs*lazy[idx]);

        if(l!=r){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }

    if(l==r){
        return tree[idx];
    }
    int mid=(l+r)/2;
    if(k<=mid)
        return findValue(2*idx+1,l,mid,k);
    else
        return findValue(2*idx+2,mid+1,r,k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    tree.resize(4*n,-1LL);
    lazy.resize(4*n,0LL); // lazy array stores the lazy propogated values, that will be required when we again come to this particular node

    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    buildTree(v,0,0,n-1);
    
    // cout<<endl<<" Tree: ";
    // for(auto it:tree)
    //     cout<<it<<" ";
    // cout<<endl;

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b,u;
            cin>>a>>b>>u;
            rangeUpdate(0,0,n-1,a-1,b-1,u); // for cses only, otherwise pass a,b
            // cout<<endl<<" Tree: ";
            // for(auto it:tree)
            //     cout<<it<<" ";
            // cout<<endl;
        }
        else{
            int k;
            cin>>k;
            cout<<findValue(0,0,n-1,k-1)<<endl;
            // cout<<endl<<" Tree: ";
            // for(auto it:tree)
            //     cout<<it<<" ";
            // cout<<endl;
        }
    }

    return 0;
}