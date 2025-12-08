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

int32_t main(){
      int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<bool> vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    vi ans;
    vi parent(n,-1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int &v : adj[u])
        {
            if (!vis[v])
            {
                parent[v] = u;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    if(!vis[n-1]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int cur = n-1;
    while( cur != -1){
        ans.push_back(cur+1);
        cur = parent[cur];
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";

    return 0;
}

