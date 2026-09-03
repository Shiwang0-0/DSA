#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> vect 
    { 
        {1, 2, 3}, 
        {4, 5, 6}
    };

    cout<<vect.size()<<endl; //gives the number of rows in the vector;

    cout<<vect[0].size()<<endl; //gives the number of colums in the vector;
 

    int n=vect.size();
    int m=vect[0].size();

    vector<vector<int>> ans(m,vector<int>(n,0)); //Declaring new vector of size m*n;
    // cout<<ans[0][2];
    
    cout<<ans.size()<<endl; //gives the number of rows in the vector;
    cout<<ans[0].size(); //gives the number of colums in the vector;


    return 0;
}