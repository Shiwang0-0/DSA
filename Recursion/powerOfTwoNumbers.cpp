#include<iostream>
using namespace std;

int power2(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    
    int ans= power2(a,b/2);


    if(!(b&1)) //even
    {
        return ans*ans;
    }
    else
    {
        return ans*ans*a;
    } 
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<< power2(a,b);
    return 0;
}