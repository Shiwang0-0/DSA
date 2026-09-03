// by defalult map sorts with respect to keys.

// To sort with respect to values, a comparator function is required.


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b)
    {
        return a.second<b.second;   // first pairs second value should be smaller than second  pairs second value. means it will be true.
    }

int main()
{
    vector<pair<int,int>>v;
    v.push_back(make_pair(43,4));
    v.push_back(make_pair(31,23));
    v.push_back(make_pair(72,23));
    v.push_back(make_pair(39,78));  

    cout<< "Normal sorting : sorting based on first parameter";
    sort(v.begin(),v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<":"<<v[i].second<<endl;
    }


    cout<<endl<<"Sort using compartor: Sorting the second parameter"<<endl;
    // sortUsingComp
    sort(v.begin(),v.end(),comp);

        for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<":"<<v[i].second<<endl;
    }
    
    return 0;
}


