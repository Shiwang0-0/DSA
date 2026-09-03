#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>
#include<set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<int>st={3,4,5,19,5,3,2};
    auto l=lower_bound(st.begin(),st.end(),365);
    cout<<*l<<endl;
    
return 0;
}