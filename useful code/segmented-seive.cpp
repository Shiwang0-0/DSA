
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>
using namespace std;

vector<int>isPrime(1000000,1);

void generateSeive(vector<int>&isPrime){
    isPrime[0]=0,isPrime[1]==0;
    for(int i=2;i*i<1000000;i++){
        if(isPrime[i]){
            for(int j=i*i;j<1000000;j+=i){
                isPrime[j]=0;
            }
        }
    }
}

vector<int> getPrimes(int n){
    vector<int>primes;
    for(int i=2;i<=n;i++){
        if(isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // to get primes in some sepecifac range, and when you cannot create 10^12 array
    
    // conditions: difference between range left and range right should be <=10^6 but range right can be as good as 10^12

    // we dont need elements beyond sqrt(right range), meaning we can create a falsy dummy array of size (right-left+1), where the indexes actually represents the left to right array ( 0 index representing the element left range, and the last index representing the right range)

    
    /*
    steps
    create a seive till 10^6

    get all primes till sqrt(r) --> in worst this will be 10^6

    create a dummy array of size r-l+1 and mark every one true

    mark all multiples of prime on dummy as false
    
    */
    

    // create seive till 10^6
    generateSeive(isPrime);

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;

        // get all primes till sqrt(r)
        vector<int>primes=getPrimes(sqrt(r));
        for(auto it:primes)
            cout<<it<<" ";
        cout<<endl;
        // make a dummy array of size r-l+1
        vector<int>dummy(r-l+1,1);
        // cout<<endl<<primes[0]<<endl;
        for(auto it:primes){    

            // get firstMultiple within left and right range
            int firstMultiple= (l/it)*it;
            if(firstMultiple<l)
                firstMultiple+=it;
            
            // start from the firstMultiple, or multiple of it, start marking them false as they can never be prime

            // max because in case like 11, where range is (110,130) the firstMultiple will come out to be 110
            // ensures that if "it" is prime, "it*it" and beyond will get marked in the loop
            for(int j=max(firstMultiple,it*it);j<=r;j+=it){
                dummy[j-l]=0;
            }

            // if left is 1, mark it as not prime
            // the above code doesnt take 1 into consideration
            if(l==1)
                dummy[0]=0;
        }

        // get all primes
        cout<<"Primes in range "<<l<<" to "<<r<<" are: " ;
        for(int i=l;i<=r;i++){
            if(dummy[i-l])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    
return 0;
}