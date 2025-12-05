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
    int n,m;cin >> n >> m;
    vector<bool>adj(n+1,0);
    for(int i=0 ,u,v;i<m;i++){
        cin >> u >> v;
        adj[u]=adj[v]=1;
    }
    cout << n-1 << endl;
    for(int i=1;i<=n;i++){
        if(!adj[i]){
            for(int j=1;j<=n;j++){
                if(i == j) {
                    continue;
                }
                cout << i << " " << j << endl;
            }
            break;
        }
    }
    return 0;
}