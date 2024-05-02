//this is question of partition dp and this a hard part of dp
//it wiint calculate the minimum number of multiplications required to calculate the product of matrices
// if we take different order of matrices and then multiply then we get different number of multiplications
// for example if we have 3 matrices A,B,C then we can multiply them in 2 ways
//let A be 10*30, B be 30*5 and C be 5*60
//then we can multiply them in 2 ways
//1. (AB)C=10*30*5+10*5*60=1500+3000=4500
//2. A(BC)=30*5*60+10*30*60=9000+18000=27000
//so we can see that the number of multiplications are different in both cases
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
//typedef long long ll;
typedef vector<int > vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
int mcm(vector<int>&a,int i,int j,vector<vector<int>>&dp){
    if(i==j){
        dp[i][j]=0;
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=a[i]*a[k]*a[j]+mcm(a,i,k,dp)+mcm(a,k+1,j,dp);
        mn=min(mn,steps);
    }
    dp[i][j]=mn;
    return mn;
}
int main()
{   
    int n;
    cout<<"Give the number of matrices:";
    cin>>n;
    vector<int>arr(n+1);//a ther are n matrices, n+1 elements are required to strore the dimensions of the matrices
    cout<<"Give the dimensions of the matrices:";
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(n+1   ,vector<int>(n+1,-1));
    cout<<"The minimum number of multiplications required to multiply the matrices is: "<<mcm(arr,0,n,dp);

    return 0;
}