
#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    map<vector<int>,int>m;

    // we are allowed to use vector as a key in cpp
    vector<int>v1={5,3,2,1,1,2};
    vector<int>v2={3,9,1,1,2,3};
    m[v1]=7;
    m[v2]=8;
    
    for(auto it:m){
        vector<int>v=it.first;
        for(auto jt:v)
            cout<<jt<<" ";
        cout<<"  val: "<<it.second<<endl;
    }
    return 0;
}


/*
#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    map<string, string> dada;
    dada["dummy"] = "papy";
    cout << dada["pootoo"];
}
*/