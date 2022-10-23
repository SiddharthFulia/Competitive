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
#define sz(x) (ll)(x).size()
const ll N=1e5+10;
vt <ll> g[N];
ll par[N];
void dfs(ll vertex,ll parent=0){
    //Take action on vertex before entering the node
    par[vertex]=parent;
    for(ll child:g[vertex]){
        //Take action on child before entering the node
      if(child==parent) continue;
        dfs(child,vertex);
        //Take action on child after entering the node
    }
    //Take action on vertex before exiting the vertex
}
vt<ll> path(vt<ll> z,ll a){
    ll var=-1;
    while(var!=1){
        z.pb(par[a]);
        var=par[a];
        a=par[a];
    }
    reverse(all(z));
    return z;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll i,n,x,y;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1); //Because 1 is starting node (change according to question)
    ll a,b;
    cin>>a>>b;//nodes input
    vt<ll> a1,b1;
    a1=path(a1,a);
    b1=path(b1,b);
    i=0;
    while(1){
        if(i==min(sz(a1),sz(b1))) break;
        if(a1[i]==b1[i]){
            i++;
        }
        else{
            break;
        }
    }
    cout<<a1[i-1];
    return 0;
}
/* INPUT
13
1 3
1 2
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9 
4 10
10 11
*/
