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
int nodes,edges;
vector<vi>adj;
vector<int>vis;
int cnt=0;
void dfs(int u ){
    vis[u]=1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int32_t main(){
    cin >> nodes >> edges;
    adj.resize(nodes+1);
    vis.resize(nodes+1,0);
    for(int i=0;i<edges;i++){
        int u,v;
       cin >> u >> v ;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vi roads;
    for(int i=1;i<=nodes;i++){
        if(!vis[i]){
            dfs(i);
            roads.push_back(i);
        }
    }
    cout << roads.size()-1 << "\n";
    for(int i=1;i<roads.size();i++){
        cout << roads[i-1] << " " << roads[i] << endl;
    }

    return 0;
}