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
const int N=3000;
const int Mod = 1000000007;
int dp[N][N];
int n,m;
vector<vector<char>>vs;
int calc(){
   if(vs[0][0] == '.') dp[0][0] = 1;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(vs[i][j] == '*') continue;
        dp[i][j] += ((i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0))%Mod;
    }
   }
   return dp[n-1][n-1];
}


int32_t main(){
    FAST
    //memset(dp,-1,sizeof(dp));
    cin >> n ;
    vs.resize(n,vc(n));
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          cin >> vs[i][j];
       }
   }
    cout << calc() << endl;
    return 0;
}
