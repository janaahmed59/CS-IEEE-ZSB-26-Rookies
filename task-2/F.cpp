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
int dI[8] = {1, 0, -1, 0, 1, 1, -1, -1},
    dJ[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vi inDegree(n);
    vector<bool>vis(n);
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        v--;u--;
        inDegree[v]++;
        adj[u].push_back(v);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        if(!inDegree[i]){
            q.push(i);
            vis[i]= true;
        }
    }
    vi order;
    while(q.size()){
        int u = q.top();
        q.pop();
        order.push_back(u);
        for(auto &v : adj[u]){
            if(!vis[v]){
                if(!--inDegree[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    
    if(order.size() != n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(auto x : order) cout << x+1 << " ";
    return 0;
}
