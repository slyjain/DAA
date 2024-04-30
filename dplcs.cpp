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
ll ** allocate2DMatrix(ll row,ll col){
    ll **matrix=new ll* [row];
    for(ll i=0;i<row;i++){
        matrix[i]=new ll[col];
    }
    for(ll i=0;i<row;i++){
        matrix[i][0]=0;
    }
    for(ll j=0;j<col;j++){
        matrix[0][j]=0;
    }
    return matrix;
}
void lcs(string s1,string s2,ll ** memo){
    ll n=s1.size();
    ll m=s2.size();
    ll mx=0;
    pair<ll,ll> lcsp;
    for( ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){ // Corrected indexing here
                memo[i][j]=1+memo[i-1][j-1];
                lcsp.F=i;
                lcsp.S=j;
                mx=max(memo[i][j],mx);
            }
            else{
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
    cout<<mx<<endl;
    ll k=mx;
    ll r=lcsp.F,c=lcsp.S;
    while(k){
        if(memo[r][c]==(1+memo[r-1][c-1])){
            cout<<s1[r-1]; // Corrected indexing here
            r=r-1;
            c=c-1;
            k--;
        }
        else{
            if(memo[r-1][c]>memo[r][c-1]){
                r=r-1;
            }
            else{
                c=c-1;
            }
        }
    }
}
int main()
{   
    string s1,s2;
    cout<<"Enter the first string:";
    cin>>s1;
    cout<<"Enter the second string:";
    cin>>s2;
    ll** memo=allocate2DMatrix(s1.size()+1,s2.size()+1);
    lcs(s1,s2,memo);

    return 0;
}