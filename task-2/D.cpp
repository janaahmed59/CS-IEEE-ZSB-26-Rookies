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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};
int n,m;
bool salka(int i,int j){
    return (i>=0 && j>=0 && i<n && j <m);
}
int32_t main(){
    cin >> n >> m;
    vector<vc>grid(n,vc(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
// find a, b -> start , end
    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A') start ={i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<vector<char>> direction(n,vc(m));

    queue<pair<int,int>>q;
    q.push(start);
    vis[start.first][start.second] = 1;

    bool found = false;
    while(q.size()){
        auto [x , y] = q.front();
        q.pop();
        if(x == end.first && y == end.second){
            found = true;
            break;
        }
        for(int i=0;i<4;i++){// check all 4dir 
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(salka(nx,ny) && grid[nx][ny]!= '#' && !vis[nx][ny]){// 
                vis[nx][ny] = true;
                direction[nx][ny]= dir[i];//push newdir and make the newdir = dir[u,l,r,d] 
                q.push({nx,ny});
            }
        }
    }
    vector<char>path;// shortestttt
    if(!found){
        cout << "NO\n";
        return 0;
    }
    else{
        int x = end.first,y = end.second;// from end to start
        while(make_pair(x,y) != start){
            path.push_back(direction[x][y]);
            if(direction[x][y] == 'U')x++;
            else if(direction[x][y] == 'D') x--;
            else if(direction[x][y] == 'L')y++;
            else if(direction[x][y]=='R') y--;
        }
        reverse(all(path));
        cout << "YES\n";
        cout << path.size() << endl;
        for(auto p : path) cout << p;
        cout << endl;
    }
    return 0;
}
