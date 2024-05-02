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

int main()
{   ll stages;
    cout<<"Enter the number of stages: ";
    cin>>stages;
    ll vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    vector<ll>cost(vertices+1);
    vector<ll>d(vertices+1);
    vector<ll>path(vertices+1);
    cost[vertices]=0;
    vector<vector<ll>>graph(vertices+1,vector<ll>(vertices+1,0));
    cout<<"Enter the cost of each edge: ";
    for(ll i=1;i<=vertices;i++){
        ll u,v;
        cin>>u>>v;
        
    }
    for(ll i=vertices-1;i>=1;i--){
        ll min=INT_MAX;
        for(ll j=i+1;j<=vertices;j++){
            if(graph[i][j]!=0 && graph[i][j]+cost[j]<min){
                min=graph[i][j];
                d[i]=j;
            }
        }
        cost[i]=min;
    }
    vector<ll>p(stages+1);
    p[1]=1;
    p[stages]=vertices;
    for(ll i=2;i<stages;i++){
        p[i]=d[p[i-1]];
    }
    return 0;
}