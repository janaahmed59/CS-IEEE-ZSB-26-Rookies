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
int n,m,k;
struct edge{
    int to , w;
    edge ( int t , int weight) : to(t), w(weight) {} // constructor
    bool operator > (const edge &e) const {
        return w > e.w; // min heap
    }
};
vector<vector<edge>> adjL;
vi dijkstra_pq(int src){
    vector<vi> prices(n+1);
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    pq.push(edge(src,0));
    prices[src].push_back(0);
    while(!pq.empty()){
        edge e = pq.top(); pq.pop();
        for(auto x : adjL[e.to]){
            int newprice = e.w + x.w;
            if(prices[x.to].size() < k){
                prices[x.to].push_back(newprice);
                pq.push(edge(x.to,newprice));
            }
            else if(newprice < *max_element(all(prices[x.to]))){
                auto it = max_element(all(prices[x.to]));
                *it = newprice;
                pq.push(edge(x.to,newprice));
            }
        }
    }
    sort(all(prices[n]));
    return prices[n];
}
int32_t main(){
    FAST
    cin >> n >> m >> k;
    adjL.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adjL[u].push_back(edge(v,w));
    }
    vi ans = dijkstra_pq(1);
    for(int i=0;i<k;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
