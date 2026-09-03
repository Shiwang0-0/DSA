#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXI=1e5;
const ll MOD=1e9+7;


vector<ll>fact(MAXI);
vector<ll>invFact(MAXI);

ll power(ll a,ll b){
    ll ans=1;
    while(b!=0){
        if(b&1)
            ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b=b/2;
    }
    return ans%MOD;
}

ll inverse(ll a){ // calculated using fermats equation, our MOD is prime and gcd(a,MOD)=1, so inverse also exist
//  If MOD is prime then any number a in range between 1<=a<=MOD-1 is coprime with MOD that is gcd(a,MOD)=1;
// this ensure that modular inverse exist for any non zero a and p.
    return power(a,MOD-2);
}

void compute_fact_invfact(){
    fact[0]=1;
    invFact[0]=1;
    for (int i = 1; i < MAXI; i++){
        // cout<<i;
        fact[i]=(fact[i-1]*i)%MOD;
        invFact[i]=inverse(fact[i]);
    }
    return;
}

void compute_ncr(ll n,ll r){
    if(n<0 || r<0 || r>n)
        return;
    ll numerator=fact[n];
    ll denominator=(invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
    cout<<"num: "<<numerator<<" deno: "<<denominator<<endl;
    cout<< (numerator*denominator)%MOD; // since inverse was calculated, multiple num and deno.
}

int main() {

    compute_fact_invfact();
    cout<<"input n and r";
    ll n,r;
    
    cin>>n>>r;

    compute_ncr(n,r);
    
return 0;
}