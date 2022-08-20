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
int height[N],depth[N];
void dfs(int vertex,int parent=0){
    
    for(int child:g[vertex]){
      if(child==parent) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
  
}
int main(){
    FastIO;
    int i,n,x,y;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1); //Because 1 is starting node (change according to question)
    for(i=1;i<=n;i++){
        cout<<depth[i]<<" "<<height[i]<<"\n";
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