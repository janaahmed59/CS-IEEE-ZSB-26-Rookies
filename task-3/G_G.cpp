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
string s,t;
const int N=3000;
int dp[N][N];

int calc(int i,int j){
    if(i == s.size() || j == t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return calc(i+1,j+1)+1;
    return dp[i][j] = max(calc(i+1,j) , calc(i,j+1));
}
string ans="";

void build(int i,int j){
    if(i == s.size() || j == t.size()) return ;

    if(s[i] == t[j]){
        ans += s[i];
        build(i+1,j+1);
    }
    else{
        if(calc(i+1,j) > calc(i,j+1)){
          build(i+1,j);
        }else{
            build(i,j+1);
        }
    }
}
int32_t main(){
    FAST
    memset(dp,-1,sizeof(dp));
    cin >> s >> t;
    build(0,0);
    cout << ans << endl; 
    return 0;
}
