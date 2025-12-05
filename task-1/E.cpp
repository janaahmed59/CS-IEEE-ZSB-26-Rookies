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
vector<bool>vis;
int comp , ed=0;
void dfs(int u ){
    comp++;
    vis[u]=1;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    ed+=adj[u].size();
}
int32_t main(){
    // check copmlete Graph
    // every node connects with all athers 
    cin >> nodes >> edges;
    adj.resize(nodes+1);
    vis.resize(nodes+1,0);
    for(int i=0;i<edges;i++){
        int u,v;
       cin >> u >> v ;
       u--;v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            comp=0,ed=0;
            dfs(i);
            ed/=2;// ofcourse the one edge is count 2-times ya janjonaa
            if(ed != (comp * (comp-1))/2){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}