#include<iostream>
using namespace std;

#define RADIX 26
#define MOD 100000007

int calculateHash(string t){
    int n=t.length();
    int factor=1,val=0;
    for(int i=n-1;i>=0;i--){
        val=(val+((t[i]-'a')*factor)%MOD)%MOD;
        factor=(factor*RADIX)%MOD;
    }
    cout<<endl;
    return val%MOD;
}

bool karpRabin(string s,string t){
    int m=s.length(),n=t.length();
    if(m<n)
        return 0;
    
    int MAXWEIGHT=1; // denotes the max value of RADIX for the target string
    for(int i=1;i<=n;i++){
        MAXWEIGHT=(MAXWEIGHT*RADIX)%MOD;
    }

    int hashT=calculateHash(t);
    // cout<<"Hash T: "<<hashT<<endl;

    int val=0;
    for(int i=0;i<=m-n;i++){
        if(i==0){ // for thes first window calculate the hash, of length same as target
            val=calculateHash(s.substr(i,n));
        }else{
            val=( ((val*RADIX)%MOD) // every prexisiting char will shift by 1, therefore introducing + 1 power of RADIX
                - (((s[i-1]-'a')*MAXWEIGHT)%MOD) // remove left most character from the window ( it had MAXWEIGHT as RADIX )
                + ((s[i+n-1]-'a')*1)  
                + MOD ) %MOD; // introduce the right most character it will have 1 as the radix.
        }
        // cout<<"Hash S: "<<val<<endl;
        if(val==hashT){
            for(int k=0;k<n;k++){
                if(t[k]!=s[i+k])
                    break;
                if(k==n-1)
                    return true; // matched at index i;
            }
            
        }
    }
    return false;
}


int main(){
    string s,t;
    cin>>s>>t;

    if(karpRabin(s,t))
        cout<<"Traget Found";
    else
        cout<<"Target Not Found";
    return 0;
}