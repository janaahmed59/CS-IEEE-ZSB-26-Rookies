//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char> 
#define all(v) v.begin(),v.end() 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vpl vector<pair<long long,long long>>
#define fr(i,n) for(int i =0;i<n;i++)
#define Popcnt(x) (__builtin_popcountll(x))
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
int n,m;
int dI[8] = {1, 0, -1, 0, 1, 1, -1, -1},
    dJ[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N=1e3+2;
char grid[N][N];
bool vis[N][N];
bool valid(int i,int j){
    return (i>=0 && i<n) && (j>=0&& j<m);
}
void dfs(int i,int j){
    vis[i][j]=true;
    for(int k=0;k<4;k++){
       int newI=i+dI[k],newJ=j+dJ[k];
        if(valid && (grid[i][j]=='.')){
            if(!vis[newI][newJ]){
                dfs(newI,newJ);
            }
        }
    }
}
int32_t main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> grid[i][j];
    }
  }
   int component=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vis[i][j] || grid[i][j] =='#') {
           continue;
        }
            dfs(i,j); 
            component++;
    }
  }
  cout << component << endl;
    return 0;
}
