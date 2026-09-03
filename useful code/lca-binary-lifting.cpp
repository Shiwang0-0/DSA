#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
void dfs(int node, int lev , int parent, vector<int>&vis, vector<int>& level,vector<vector<int>> &dp){
    level[node] = lev;
    vis[node] = 1;
    dp[0][node] = parent;
    
    for(auto &x:adj[node]){
        if(!vis[x])
            dfs(x,lev+1,node,vis,level,dp);
    }
}

void binaryLift(int n, vector<vector<int>>& dp){
    
    for(int i=1;i<32;++i){
        for(int j=0;j<n;++j){
            if(dp[i-1][j] != -1)
                dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}
int getLCA(int n1,int n2,vector<int>& level,vector<vector<int>> &dp){
    int l1 = level[n1];
    int l2 = level[n2];
    
    if(l1>l2){
        swap(l1,l2);
        swap(n1,n2);
    }
        
    
    int k = l2-l1;
    for(int i=0;i<32;++i){
        if(k & (1<<i)){
            n2 = dp[i][n2];
        }
    }
    
    // cout<<l1<<" "<<l2<<" "<<n1<<" "<<n2<<endl;
    if(n1 == n2)
        return n1;
    
    for(int i=31;i>=0;--i){
        int n1p = dp[i][n1];
        int n2p = dp[i][n2];
        if(n1p != n2p){
            n1 = n1p;
            n2 = n2p;
        }
    }
    
    return dp[0][n1];
    
}
void answerQueries(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    
    for(auto &edge: B){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<int>level(A+1,-1);
    vector<vector<int>> dp(32,vector<int>(A+1,-1));
    vector<int>vis(A+1,0);
    
    dfs(1,1,-1,vis,level,dp);
    binaryLift(A+1,dp);
    
    // for(int i=0;i<32;++i){
    //     for(int j=0;j<=A;++j){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(auto &x:C){
        cout<<getLCA(x[0],x[1],level,dp)<<endl;
    }
}
        
int main(){
    int A;
    cin>>A;
    vector<vector<int>>B;
    for(int i=0;i<5;++i){
        int n1,n2;
        cin>>n1>>n2;
        B.push_back({n1,n2});
    }
    vector<vector<int>>C;
    for(int i=0;i<3;++i){
        int n1,n2;
        cin>>n1>>n2;
        C.push_back({n1,n2});
    }
    answerQueries(A,B,C);
}