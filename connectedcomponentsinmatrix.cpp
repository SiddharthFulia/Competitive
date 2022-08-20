//Question link https://leetcode.com/problems/flood-fill/submissions/
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

void dfs(vector<vector<int>>& image,int i,int j,int newColor,int n,int m,int initialcolor){
    if(i<0||j<0||i>=n||j>=m) return;
    if(image[i][j]!=initialcolor) return;
    image[i][j]=newColor;
    dfs(image,i-1,j,newColor,n,m,initialcolor);
    dfs(image,i+1,j,newColor,n,m,initialcolor);
    dfs(image,i,j+1,newColor,n,m,initialcolor);
    dfs(image,i,j-1,newColor,n,m,initialcolor);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int n=image.size();
      int m=image[0].size();
      int initialcolor=image[sr][sc];
      if(initialcolor!=newColor)
        dfs(image,sr,sc,newColor,n,m,initialcolor);
      return image;
}
int main(){
    FastIO;
    
  
    return 0;
}