#include<iostream>
#include<algorithm>
#include <limits.h>
using namespace std;

// Tip: make sure to initialize the arrays with 0.

int main()
{
    int n,e;
    cin>>n;
    int v[100]={0};

    // making input array
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    cout<<endl;
    
    // find max element to make C array
    int maxEle=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>maxEle)
            maxEle=v[i];
    }

    // if max is 5, C will contain 6 element ( considering 0 also )
    maxEle=maxEle+1;

    // store frequency of elements
    int C[maxEle]={0};
    for (int i = 0; i < n; i++)
    {
        C[v[i]]++;
    }

    cout<<endl;

    for (int i = 0; i < maxEle; i++)
    {
        cout<<C[i];
    }

    // make Cdash array
    int Cdash[maxEle]={0};
    Cdash[0]=C[0]; // first element is same as that of C
    // add cross elements
    for (int i = 1; i < maxEle; i++)
    {
        Cdash[i]=Cdash[i-1]+C[i];
    }

    cout<<"\nC dash array \n";
    for (int i = 0; i < maxEle; i++)
    {
        cout<<Cdash[i];
    }


    int out[n]={0};

    for (int i = 1; i <= n; i++)
    {
        // take final of input
        int finalEle=v[n-i]; // last ele of inout array, and then move towards the left.
        int indexOfOutput=Cdash[finalEle]; 

        out[indexOfOutput-1]=finalEle;
        Cdash[finalEle]=Cdash[finalEle]-1;
    }

    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<out[i];
    }

    return 0;
}

/*
#include<iostream>
#include<algorithm>
#include <limits.h>
#include<bits/stdc++.h>
using namespace std;

// Tip: make sure to initialize the arrays with 0.
    
void countSort(vector<int>&nums){
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int>countingArray(maxi+1,0); // stores count
        for(int i=0;i<n;i++){
            countingArray[nums[i]]++;
        }
        int j=0;
        for(int i=0;i<maxi+1;i++){
            int count=countingArray[i];
            while(count--){
                nums[j]=i;
                j++;
            }
        }

        for(auto it:nums)
            cout<<it<<" ";
    }

int main()
{
    int n,e;
    cin>>n;
    vector<int>v(n);

    // making input array
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    countSort(v);
    cout<<endl;

    return 0;
}

*/