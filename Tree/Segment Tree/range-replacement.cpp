// You are given an array A of size N. You are allowed to choose at most one pair of elements such that distance (defined as the difference of their indices) is at most K and swap them. Find the smallest lexicographical array possible after swapping.

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int value,index;
};

class SegmentTree{

    public:
        int n;
        vector<Node>tree;

        SegmentTree(vector<int>&arr){
            n=arr.size();
            tree.resize(4*n);
            buildTree(arr,0,0,n-1);
        }
        
        void printTree(){
            for(auto it:tree)
                cout<<it.value<<" ";
            cout<<endl;
        }

        Node query(int l,int r){
            return query(l,r,0,0,n-1);
        }

    private:

        Node minimumNode(Node a,Node b){
            if(a.value==b.value){
                if(a.index>b.index) return a;
                return b;
            }
            else{
                if(a.value>b.value) return b;
                return a;
            }
        }

        
        void buildTree(vector<int>&arr,int idx,int l,int r){
            if(l==r){
                tree[idx]={arr[l],l};
                return;
            }
            int mid=(l+r)/2;

            buildTree(arr,2*idx+1,l,mid);
            buildTree(arr,2*idx+2,mid+1,r);

            tree[idx]=minimumNode(tree[2*idx+1],tree[2*idx+2]);
        }

        Node query(int l,int r,int idx,int a,int b){
            if(a>=l && b<=r)
                return tree[idx];
            if(b<l || a>r)
                return {INT_MAX,-1};

            int mid=(a+b)/2;
            Node left=query(l,r,2*idx+1,a,mid);
            Node right=query(l,r,2*idx+2,mid+1,b);
            return minimumNode(left,right);
        }


};

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    SegmentTree st(a);

    int k;
    cin>>k;

    for(int i=0;i<n;i++){
        int l=i,r=i+k-1;
        cout<<l<<" "<<r<<endl;
        Node  curr=st.query(l,r);
        cout<<curr.value<<" "<<curr.index<<endl;
        if(curr.value<a[i]){
            swap(a[i],a[curr.index]);
            break;
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    

    return 0;
}
