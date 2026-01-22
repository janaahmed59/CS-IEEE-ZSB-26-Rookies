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
    FAST
   int n,x;cin >> n >> x;
    vi price(n),pages(n);
    cin >> price >> pages;
    vi dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int j=x;j>=price[i];j--){
            dp[j] = max(dp[j],dp[j-price[i]]+pages[i]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}
