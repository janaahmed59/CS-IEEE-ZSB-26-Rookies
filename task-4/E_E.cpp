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

const int oo = 1e18;
vi dijkstra_pq(int src , int dest, vector<vector<pii>>& adj){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vi vis(dest+1,oo);
    pq.push({0,src});
    vis[src] = 0;
    while(!pq.empty()){
        auto e = pq.top(); pq.pop();
        int x=e.first; int y = e.second;
        if(e.first > vis[e.second]) continue;
        for(auto ne : adj[y]){
            int curr = x + ne.second;
            if(vis[ne.first] > curr){
                vis[ne.first] = curr;
                pq.push({curr,ne.first});
            }
        }
    }
    return vis;
}
int32_t main(){
    FAST
    int n,m;
    cin >> n >> m;
    vector<vector<pii>>adjL(n+1),adj(n+1);

    vector<vi>edges;
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adjL[u].push_back({v,w});
        adj[v].push_back({u,w}); 
        edges.push_back({u,v,w});
    }
    vi ans1 = dijkstra_pq(1,n,adjL);
    vi ans2 = dijkstra_pq(n,n,adj);

    int res = oo;
    for(auto e: edges){
        int curr = ans1[e[0]] + ans2[e[1]] + e[2]/2; 
        res = min(res,curr);
    }
    cout << res << "\n";
    return 0;
}
