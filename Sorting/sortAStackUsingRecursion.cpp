#include <bits/stdc++.h> 
#include<iostream>
#include<stack>
using namespace std;


stack<int> solve(stack<int>&s, int temp)
{
	if(s.empty() || s.top()<temp)
	{
		s.push(temp);
		return s;
	}

	int temp2=s.top();
	s.pop();
	solve(s,temp);
	s.push(temp2);
	return s;
}

void sortStack(stack<int> &s)
{
	// Write code here.
	if(s.empty())
		return;
	
	int temp=s.top();
	s.pop();
	sortStack(s);

	solve(s,temp);
}




int main()
{
    stack<int>s;
    int n,val=0;
    cout<<"enter the size"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        s.push(val);
    }
    sortStack(s);

    for (int i = 0; i < n && !s.empty(); i++)
    {
        cout<<s.top();
        s.pop();
    }
    

    return 0;
}