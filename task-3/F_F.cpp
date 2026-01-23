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

int n;
vi a,b,c;

// int knapsack(int i,int j){
//     if(i==n) return 0;
//     if(dp[i][j] != -1) return dp[i][last];
    
//     if(j == 0){
//         int take = knapsack(i+1)
//     }
//     if(last == 0){
//         // int takeB = knapsack(i+1,1) + b[i];
//         // int takeC = knapsack(i+1,2) + c[i];
//         return dp[i][last] = max(,takeC);
//     }
//     else if(last == 1){
//         int takeA = knapsack(i+1,0) + a[i];
//         int takeC = knapsack(i+1,2) + c[i];
//         return dp[i][last] = max(takeA,takeC);
//     }
//     else{
//         int takeA = knapsack(i+1,0) + a[i];
//         int takeB = knapsack(i+1,1) + b[i];
//         return dp[i][last] = max(takeA,takeB);
//     }
// }
int32_t main(){
    FAST
    cin >> n;
    a.resize(n);b.resize(n);c.resize(n);
   vector<vector<int>>dp(n,vector<int>(3));
    for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i][0] = a[i];
            dp[i][1] = b[i];
            dp[i][2] = c[i];
        }
        else{
            dp[i][0]= a[i] + max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]= b[i] + max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]= c[i] + max(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;

    return 0;
}
