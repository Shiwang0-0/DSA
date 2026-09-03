#include<iostream>
using namespace std;

#define RADIX_1 26
#define MOD_1 100000007

#define RADIX_2 27
#define MOD_2 100000033

int calculateHash(string t,int RADIX,int MOD){
    int n=t.length();
    long long factor=1,val=0;
    for(int i=n-1;i>=0;i--){
        val=(val+((t[i]-'a')*factor)%MOD)%MOD;
        factor=(factor*RADIX)%MOD;
    }
    // cout<<endl; 
    return val%MOD;
}

bool karpRabin(string s,string t){
    int m=s.length(),n=t.length();
    if(m<n)
        return 0;
    
    long long MAXWEIGHT_1=1; // denotes the max value of RADIX_1 for the target string
    for(int i=1;i<=n;i++){
        MAXWEIGHT_1=(MAXWEIGHT_1*RADIX_1)%MOD_1;
    }
    long long MAXWEIGHT_2=1; // denotes the max value of RADIX_2 for the target string
    for(int i=1;i<=n;i++){
        MAXWEIGHT_2=(MAXWEIGHT_2*RADIX_2)%MOD_2;
    }

    pair<int,int> hashT;
    hashT.first=calculateHash(t,RADIX_1,MOD_1);
    hashT.second=calculateHash(t,RADIX_2,MOD_2);
    // cout<<"Hash T: "<<hashT<<endl;

    long long val1=0,val2=0;
    for(int i=0;i<=m-n;i++){
        if(i==0){ // for thes first window calculate the hash, of length same as target
            val1=calculateHash(s.substr(i,n),RADIX_1,MOD_1);
            val2=calculateHash(s.substr(i,n),RADIX_2,MOD_2);
        }else{
            val1=( ((val1*RADIX_1)%MOD_1) // every prexisiting char will shift by 1, therefore introducing + 1 power of RADIX_1
                - (((s[i-1]-'a')*MAXWEIGHT_1)%MOD_1) // remove left most character from the window ( it had MAXWEIGHT as RADIX_1 )
                + ((s[i+n-1]-'a')*1)  
                + MOD_1 ) %MOD_1; // introduce the right most character it will have 1 as the RADIX_1.

            val2=( ((val2*RADIX_2)%MOD_2) // every prexisiting char will shift by 1, therefore introducing + 1 power of RADIX_1
                - (((s[i-1]-'a')*MAXWEIGHT_2)%MOD_2) // remove left most character from the window ( it had MAXWEIGHT as RADIX_1 )
                + ((s[i+n-1]-'a')*1)  
                + MOD_2 ) %MOD_2; // introduce the right most character it will have 1 as the RADIX_1.
        }

        if(val1==hashT.first && val2==hashT.second){ // both hash should match
            // for(int k=0;k<n;k++){
            //     if(t[k]!=s[i+k])
            //         break;
            //     if(k==n-1)
            //         return true; // matched at index i;
            // }
            return true; // do not need to check for every character now because the probablity of that in double hashing is 10^-10 
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