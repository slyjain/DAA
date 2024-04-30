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

int lcs(string s1, string s2, int i, int j){
    static vector<vector<int>>memo(s1.size());
    for(int i=0;i<s1.size();i++){
        memo[i].resize(s2.size(),-1);
    }
if(memo[i][j]!=-1)
        return memo[i][j];

    if(s1[i]=='\0'||s2[j]=='\0'){

        memo[i][j]=0;
        return 0;
    }
    else if(s1[i]==s2[j]){
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j]=1+lcs(s1,s2,i+1,j+1);
        return 1+lcs(s1,s2,i+1,j+1);
    }
    
    memo[i][j]=max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
}
int main()
{   ios_base::sync_with_stdio(false);
    

    string s1,s2;
    cout<<"Enter the first string : ";
    cin>>s1;
    cout<<"Enter the second string : ";
    cin>>s2;

    cout<<"Longest common subsequence is of size : "<<lcs(s1,s2,0,0);
    return 0;
}