#include<iostream>
using namespace std;

int main(){
    int n,i;
    cin>>n;
    cin>>i;
    cout<<"printing ith bit"<<endl;
    cout<<((n&(1<<i))!=0);

    cout<<"toggle"<<endl;
    n=n^(1<<i);

    cout<<"printing ith bit"<<endl;
    cout<<((n&(1<<i))!=0);
    return 0;
}