#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int>v={0,1,2,3,4};
    vector<int>nums={6,2,8,1,9};

    sort(v.begin(),v.end(),[&](int a,int b)-> bool{
        return nums[a]<nums[b];
    });
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}