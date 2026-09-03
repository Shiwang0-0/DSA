#include<iostream>
#include<algorithm>
#include <limits.h>
#include<math.h>
using namespace std;

void countSort(int v[],int exp,int n){
    int out[n]={0};
    int count[10]={0}; // for digit wise, max a digit can be 10 only.


    // making freq array
    for(int i=0;i<n;i++)
        count[(v[i]/exp)%10]++; // (v[i]/exp)%10  gives that exp digit we need to sort currently

    cout<<"count for exp "<<exp<<" is: ";
    for (int i = 0; i < 10; i++)
        cout<<count[i]<<" ";
    cout<<endl;


    // making prefix freq array
    int countDash[10]={0};
    countDash[0]=count[0];
    for (int i = 1; i < 10; i++)
        countDash[i]=countDash[i-1]+count[i];

    cout<<"countDash for exp "<<exp<<" is: ";
    for (int i = 0; i < 10; i++)
        cout<<countDash[i]<<" ";
    cout<<endl;


    for(int i=n-1;i>=0;i--){ // here we dont want the element like counting sort, but we want to compare the exp digit only from last element
        int expDigitOfEle=(v[i]/exp)%10; // search this-1 index in countDash array
        int indexOfOutput=countDash[expDigitOfEle]-1; // now search the desired location in the output array 

        out[indexOfOutput]=v[i]; 
        countDash[expDigitOfEle]--;
    }

    // copy the sorted output back to the original array, to reflext the current exp digit changes
    for (int i = 0; i < n; i++)
        v[i] = out[i];

    cout << "output for exp " << exp << " is: ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void radixSort(int v[],int n)
{

    int maxEle=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>maxEle)
            maxEle=v[i];
    }

    int MaxEleDigit=floor(log10(maxEle)+1);
    cout<<"mmaxDigits: "<<MaxEleDigit<<endl;

    for (int i = 1; MaxEleDigit-- ; i*=10)
    {
        countSort(v,i,n); // do count sort in array for the exponent ones, tens hundred
    }
}



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

    
    radixSort(v,n);
    

    return 0;
}