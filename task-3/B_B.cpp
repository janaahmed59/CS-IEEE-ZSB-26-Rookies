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
vi v;
int n, k;
const int N=1e5+12;
int dp[N];
int calc(int i){
    if(i==n-1)return 0;
    if(dp[i] != -1) return dp[i];
    int cost = 1e18;
    for(int j=1;j<=k;j++){
        if(i+j<n)
        cost = min(cost, calc(i+j) + abs(v[i]-v[i+j]));
    }
    return dp[i]=cost ;
}
int32_t main(){
    FAST
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    v.resize(n);
    cin >> v;
    cout << calc(0) << endl;
    return 0;
}