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

vi prevv; // to update tha path 
vi dist; // to store distance from source
vi vis; // to check if node is visited or not
int n,m;
struct edge{
    int from , to , w;
    edge (int f , int t , int weight) : from(f), to(t), w(weight) {} // constructor
    bool operator < (const edge &e) const {
        return w > e.w; // min heap
    }
};
vector <vector<edge>> adjL;

int dijkstra_pq (int src , int dest){
    priority_queue<edge> pq;
    dist[src] = 0;
    pq.push(edge(-1,src,0));
    while(!pq.empty()){
        edge e = pq.top(); pq.pop();
        if(e.w > dist[e.to]) continue; 

        //prevv[e.to] = e.from;
        for(auto &ne : adjL[e.to]){
            if(dist[ne.to] > dist[e.to] + ne.w){
                dist[ne.to] = dist[e.to] + ne.w;
                pq.push(edge(e.to,ne.to,dist[ne.to]));
            }
        }
    }
    return dest == -1 ? -1 : dist[dest];
}
int32_t main(){
    FAST
    cin >> n >> m;
    adjL.resize(n+1);
    dist.resize(n+1,oo);
    prevv.resize(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adjL[u].push_back(edge(u,v,w));// directed graph
    }
    dijkstra_pq(1,-1);
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    return 0;
}
