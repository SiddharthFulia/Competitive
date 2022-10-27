//https://www.codechef.com/SNCKPB17/problems-old/SNSOCIAL
#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (int)(x).size()
const ll N=1e3+10;
const ll M=1e9+7;
ll n,m;
ll val[N][N];
ll vis[N][N];//visited array
ll level[N][N];
bool isValid(ll x,ll y){
    return x>=0 && y>=0 && x<n && y<m;
}
//vector for movement of knight
vt<pair<ll,ll>> movements={
    {1,0},{-1,0},{0,1},{0,-1},
    {1,1},{-1,1},{1,-1},{-1,-1}
};
void reset(){
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vis[i][j]=0;
            level[i][j]=M;
        }
    }
}
ll bfs(){
    ll i,j,max1=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            max1=max(max1,val[i][j]);
        }
    }
     queue<pair<ll,ll>> q;
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           if(max1==val[i][j]){
            q.push({i,j});
            level[i][j]=0;
            vis[i][j]=1;
           }
        }
    }
    ll ans=0;
     while(!q.empty()){
        pair<ll,ll> v=q.front();
        q.pop();
        for(auto movement:movements){
            ll childx=movement.first+v.first;
            ll childy=movement.second+v.second;
            if(!isValid(childx,childy)) continue;
            if(!vis[childx][childy]){
                q.push({childx,childy});
                level[childx][childy]=level[v.first][v.second]+1;
                vis[childx][childy]=1;
            }
            ans=max(ans,level[childx][childy]);
        }
     }
     return ans;
}
void solve(){
    ll i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>val[i][j];
        }
    }
    cout<<bfs();
    cout<<"\n";
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t;
    cin>>t;
    while(t--){
        reset();
        solve();
    }
    return 0;
}
/* INPUT
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
*/
