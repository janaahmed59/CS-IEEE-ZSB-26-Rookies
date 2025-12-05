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
int dI[8] = {1, 0, -1, 0, 1, 1, -1, -1},
    dJ[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int n,m,k;
vector<vector<char>>adj;
vector<vector<bool>>vis;
bool valid(int i,int j){
   return i>=0 && j>=0 && i<n && j<m;
}
void dfs(int i,int j){
    vis[i][j] = 1;
    for(int d=0;d<4;d++){
        int newI=i+dI[d] , newJ=j+dJ[d];
        if(valid(newI,newJ) && adj[newI][newJ] == '.'){
            if(!vis[newI][newJ]) dfs(newI,newJ);
        }
    }
    if(k) {
       adj[i][j] = 'X';
       k--;
    }
}
int32_t main(){
  cin >> n >> m >> k;
  adj.assign(n,vector<char>(m));
  vis.assign(n ,vector<bool>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> adj[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && adj[i][j] == '.' && k){
            dfs(i,j);
        }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout << adj[i][j];
    }
      cout << endl;
    }
    return 0;
}
