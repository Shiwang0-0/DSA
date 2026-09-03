#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void ZAlgo(string s,vector<int>&z){
    int l=0,r=0,n=s.length();

    // z[0] remains 0
    for(int k=1;k<n;k++){
        if(k>r){ // for now r is less than current k, meaning we dont have enough window 
            l=k; // current element se compare kerna shuru kerunga and window maintain kerunga
            r=k;
            while(r<n && s[r]==s[r-l]) // compare  kerna h current element se prefix ko.
                r++;
            z[k]=r-l; // itne elements match hue hai prefix se
            r--; // tu r++ pe while se bhar nikla tha..to ek kam to ker
        }
        else{ // r surpasses k, meaning there are more than 1 character that matches previous characters
              // k is between l and r, k is inside the window
            int k1=k-l; // left of the current index k inside the window which is also equal to the maching index in the prefix.
            // kyuki window ho rhi thi l se start, and tum abhi ho k pe... and prefix mai tumhe current k vala index milega k-l se..kyuki prefix to humesha 0 se hi start hota h.
            
            if(z[k1]+k<r+1){ // jo add kerne ki sochi vo still is in my phele se dekhi hui range m h.
                z[k]=z[k1];
            }
            else{   // jo index mai lene ki sochra tha.. vo to meri range ko hi exceed kerdera.
                    // aur mene abhi beyond r rvale elements dekhe ni.. to i cannot say about it yet.
                    // window i shrink kerni padegi 
                l=k;
                while(r<s.length() && s[r]==s[r-l]){
                    r++;
                }
                z[k]=r-l; // itne elements match hue hai prefix se
                r--; // tu r++ pe while se bhar nikla tha..to ek kam to ker
            }
        }
    }
    return;
}

int main(){
    string s,t;
    cin>>s>>t;

    string ss=s+'$'+t; // string which we will work on
    int n=ss.length();

    vector<int>z(n,0);
    ZAlgo(ss,z);

    for(auto it:z)
        cout<<it<<" ";

    return 0;
}