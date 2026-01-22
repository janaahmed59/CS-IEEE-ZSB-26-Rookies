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
vi v,w;
int n, m;
const int N=100, M=1e5+10;
int dp[N][M];
int knapsack(int i,int sum){
     if(sum > m) return -1234446223453;
     if(i == n) return 0;

    if(dp[i][sum] != -1) return dp[i][sum];

    int take = knapsack(i+1,sum+w[i])+v[i];
    int Not_take = knapsack(i+1,sum);

    return dp[i][sum] = max(take, Not_take);
}
int32_t main(){
    FAST
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    v.resize(n);w.resize(n);
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i] ;
    }
    cout << knapsack(0,0) << endl;

    return 0;
}