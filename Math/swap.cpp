#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"swapping"<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b;
    return 0;
}