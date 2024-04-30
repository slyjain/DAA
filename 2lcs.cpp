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
ll ** allocate2DMatrix(ll rows,ll cols){
    ll** matrix=new ll*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new ll[cols];
    }
    return matrix;
}
ll lcs(string s1,string s2,ll i,ll j,ll **memo){
     
    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    if(s1[i]=='\0'||s2[j]=='\0'){
            memo[i][j]=0;
        return 0;
    }
    else if(s1[i]==s2[j]){
        memo[i][j]=1+lcs(s1,s2,i+1,j+1,memo);
        return memo[i][j];
    }
    else{
        int x=max(lcs(s1,s2,i+1,j,memo),lcs(s1,s2,i,j+1,memo));
        memo[i][j]=x;
        return x;
    }
    return 0;
}
int main()
{   ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    string s1,s2;

    cout<<"\nGive the first string :";
    cin>>s1;
    cout<<"\nGive the second string :";
    cin>>s2;
    // cout<<endl<<s1.size()<<"\n";
    ll **memo=allocate2DMatrix(s1.size()+1,s2.size()+1);
    for(ll i=0;i<s1.size()+1;i++){
        for(ll j=0;j<s2.size()+1;j++){
            memo[i][j]=-1;
        }
    }
    cout<<"\nThe longest common subsequence from s1 and s2 is of length :"<<lcs(s1,s2,0,0,memo)<<endl;
    for(ll i=0;i<s1.size()+1;i++){
        for(ll j=0;j<s2.size()+1;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}