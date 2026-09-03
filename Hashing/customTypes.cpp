#include<iostream>
#include<bits/stdc++.h>
#include <unordered_map>
#include <string>

using namespace std;

struct customHashFunction{  // would typically return integer
    int operator()(string s) const {
        int myPookieHash=0;
        for(auto it:s)
            myPookieHash=myPookieHash*9+(it-'a');  // just for example
        cout<<"hash for string "<<s<<" is: "<<myPookieHash<<endl;
        return myPookieHash;
    }  
};

// struct customHashFunction {
//     size_t operator()(const string& s) const {
//         cout<<"hash for string: "<<s<<" is: "<<s.length()<<endl;
//         return s.length();  // Simple hash based on string length
//     }
// };

struct equalityCheck{
    // Everywhere the standard library uses the Compare requirements, uniqueness is determined by using the equivalence relation. In imprecise terms, two objects a and b are considered equivalent (not unique) if neither compares less than the other: !comp(a, b) && !comp(b, a).
    // ref: https://en.cppreference.com/w/cpp/container/map
    bool operator()(string a,string b)const {
        return a==b;
    }
};

int main(){
    unordered_map<string,int,customHashFunction,equalityCheck>m;
    
    m["hola"]=5;
    m["namaste"]=10;
    m["ciao"]=9;
    m["konichiwa"]=2;
    for(auto it:m)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}