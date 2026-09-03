#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // int variable;
    // scanf("%d",&variable);
    int arr[3248];   //Generally in standard C++ this is not valid,passing a varibale which is to be decided in the run time is not accepted in C++ earlier.Because the memory allocation for the array is in the compile time itself.
    cout<<sizeof(arr);
    return 0;
}
