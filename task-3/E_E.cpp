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
   int n; cin >> n;
    vi v(n);
    cin >> v;
    int maxsum=0;
    for(int i=0;i<n;i++) maxsum+=v[i];// max possible sum

    vector<bool> dp(maxsum+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=maxsum;j>=0;j--){
            if(dp[j]) dp[j+v[i]]=true;
        }
    }
    vi ans;
    for(int i=1;i<= maxsum;i++){
        if(dp[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
