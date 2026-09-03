#include<iostream>
using namespace std;

int main(){
    int n,i;
    cin>>n;
    cin>>i;

    if(n&(1<<i)==0)
        cout<<"0";
    cout<<"1";
    return 0;
}