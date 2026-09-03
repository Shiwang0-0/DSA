
/*
void solve(stack<int>&s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    solve(s,temp);
    s.push(val);
    return;
}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty())
        return;
    int temp=s.top();
    s.pop();
    reverseStack(s);
    solve(s,temp);
}
*/