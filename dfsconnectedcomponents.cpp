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
const int N=1e5+10;
vt <int> g[N];
bool vis[N];
void dfs(int vertex){
    /*Take action on vertex after entering the vertex*/
    // if(vis[vertex]) return; //(also used)
    vis[vertex]=true;
    for(int child:g[vertex]){
        /*Take action on child before entering the child node*/
        if(vis[child]) continue;
        dfs(child);
        /*Take action on child after exiting the child node*/
    }
    /*Take action on vertex after exiting the vertex*/
}
int main(){
    FastIO;
    int i,n,e,count=0;
    cin>>n>>e;
    for(i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(vis[i]==1) continue;
        dfs(i);
        count++;
    }
    cout<<count;
    return 0;
}