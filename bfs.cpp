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
vt <ll> g[N];
ll vis[N];//visited array
ll level[N];
void bfs(ll source){
    queue<ll> q;
    q.push(source);
    vis[source]=1;//markig the visited node
    while(!q.empty()){
        ll cur_v=q.front();//current vertex
        q.pop();
        cout<<cur_v<<" ";//(check queue sequence)
        for(auto child:g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
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
    bfs(1);
    for(i=1;i<=n;i++){
        cout<<"\nLevel of "<<i<<" is:"<<level[i];
    }
    return 0;
}
/* INPUT
13
1 2
1 3
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
