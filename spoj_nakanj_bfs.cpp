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
const ll N=1e5+10;
const ll M=1e9+7;
ll vis[8][8];//visited array
ll level[8][8];
ll getx(string s){
    return s[0]-'a';
}
ll gety(string s){
    return s[1]-'1';
}
bool isValid(ll x,ll y){
    return x>=0 && y>=0 && x<8 && y<8;
}
//vector for movement of knight
vt<pair<ll,ll>> movements={
    {1,2},{-1,2},
    {1,-2},{-1,-2},
    {2,1},{-2,1},
    {2,-1},{-2,-1}
};
void reset(){
    ll i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            vis[i][j]=0;
            level[i][j]=N;
        }
    }
}
ll bfs(string source,string destination){
     ll sourcex=getx(source);     
     ll sourcey=gety(source); 
     ll destinationx=getx(destination);     
     ll destinationy=gety(destination); 
     queue<pair<ll,ll>> q;
     q.push({sourcex,sourcey});
     vis[sourcex][sourcey]=1;
     level[sourcex][sourcey]=0;
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
        }
        if(level[destinationx][destinationy]!=N){
            break;
        }
     }
     return level[destinationx][destinationy];
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    reset();
    cout<<bfs(s1,s2);
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
        solve();
    }
    return 0;
}
/* INPUT
3
a1 h8
a1 c2
h8 c3
*/
