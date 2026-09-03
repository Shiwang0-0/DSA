#include<iostream>
using namespace std;

void func(int a,int b)
{
    
    cout<<a<<endl;
    a=5;
    a++;
    func(a,b);
}

int main()
{
    int a=5,b=10;
    func(a,b);
    return 0;
}