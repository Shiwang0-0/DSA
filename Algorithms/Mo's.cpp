#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<math.h>
using namespace std;


// Mo wont work here, since it takes n*sqrt(n) in worst case for n queries.


void func(long long queries[][2],vector<long long>v,long long n,long long q){

    vector<long long>prefix(n,0);
    prefix[0]=v[0];
    for(int i=1;i<n;i++){
        prefix[i]=v[i]+prefix[i-1];
    }
    for(int i=0;i<q;i++){
        int l=queries[i][0]-1,r=queries[i][1]-1;
        long long ans=0;
        if(l>0)
            ans=prefix[r]-prefix[l-1];
        else if(l==0)
            ans=prefix[r];
        cout<<ans<<endl;
    }
    
}

int main() {
    
    long long n,q;
    cin>>n;
    cin>>q;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    long long queries[q][2];
    for(long long i=0;i<q;i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
    }

    func(queries,v,n,q);
    
 
return 0;
}
