#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

bool comp(int a,int b){
    return a<b;
}

int main()
{
    map<int,int>m;
    m[1]=5;
    m[2]=3;
    m[3]=6;

    sort(m.begin(),m.end(),comp);

    for(auto it:m){
        cout<<it.second<<" ";
    }
    return 0;
}