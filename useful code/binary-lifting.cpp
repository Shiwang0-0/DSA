#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,q,x,k;
    cin>>n>>q;
    
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++){
        cin>>parent[i];
    }
    vector<vector<int>>dp(30,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        dp[0][i]=parent[i];
    }

    // dp[i][j] stores that when i steps are taken from node j, where it will land
    for(int i=1;i<=30;i++){
        for(int node=1;node<=n;node++){
            dp[i][node]=dp[i-1][dp[i-1][node]];
        }
    }

    while(q--){
        cin>>x>>k;
        int node=x;
        for(int i=1;i<=30;i++){
            if(k & (1<<i)){
                node=dp[i][node];
            }
        }
        cout<<node<<endl;
    }


    return 0;
}   