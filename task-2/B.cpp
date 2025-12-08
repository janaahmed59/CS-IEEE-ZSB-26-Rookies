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
int n,m;
vector<vi>adj(n+1);
vi color(n+1,-1);
vi cnt;
int32_t main(){
    cin >> n ;
    adj.resize(n+1);
    color.resize(n+1,-1);
    cnt.resize(3);
    for(int i=0,u,v;i<n-1;i++){
       cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    bool flag = true;
    //int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        if(color[i] == -1){
        queue<int> q;
        q.push(i);
        color[i] = 1;
        cnt[i]++;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                    cnt[color[v]]++;
                }
            }
        }
    }
}
    cout << cnt[1] * cnt[0] - (n-1) << endl;
    return 0;
}