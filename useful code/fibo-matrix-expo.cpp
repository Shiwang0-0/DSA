#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<long long>>matrix;
const int MOD=1e9+7;

matrix IdentityMatrix(){
    matrix identity(2,vector<long long>(2,0));
    identity[0][0]=1;
    identity[1][1]=1;
    return identity;
}

matrix matrixMultiplication(matrix& a,matrix& b){
    int n1=a.size(),m2=b[0].size();
    matrix ans(2,vector<long long>(2,0));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            long long sum=0;
            for(int k=0;k<n1;k++){
                sum=sum+(a[i][k]*b[k][j]);
            }
            ans[i][j]=sum;
        }
    }
    return ans;
}

matrix matrixExponentiation(matrix base,int expo){
    if(expo==0){ // return identity matrix
        return IdentityMatrix();
    }
    matrix half=matrixExponentiation(base,expo/2);
    matrix result=matrixMultiplication(half,half);
    if(expo%2==1){
        result=matrixMultiplication(result,base);
    }
    return result;
}

int main(){
    int n=0,m;
    cin>>m;

    while(n<m){
        if(n==0){
            cout<<0<<" ";
            n++;
            continue;
        }

        matrix T ={{1,1},{1,0}}; // 2x2
        matrix mat={{1},{0}}; // 2x1

        matrix matpown= matrixExponentiation(T,n-1); // returned matrix will be of 2x2

        matrix result=matrixMultiplication(matpown,mat);

        cout<<result[0][0]<<" ";
        n++;
    }
    return 0;
}