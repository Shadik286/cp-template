#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define EPS 1e-9
int cas = 0;
 
#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)
 
#define print_case cout << "Case " << ++cas << ": "
#define mod (int) 1e9+7
const int N = 9e5+7;
const int INF = INT64_MAX;
using namespace std;


vector<int>adj[N];

struct BFS{
    int n; 
    vector<int>visited, par;
    
    BFS (int n) {
      this->n = n; 
      visited.resize(n + 1), par.resize(n + 1); 
      for(int i = 0; i <= n + 5; i++) adj[i].clear();
    } 

    void input(int m) {
      for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        adj[a].push_back(b); adj[b].push_back(a);
      }
    } 

    bool bfs(int strt = 1) {
      queue<int>q; 
      q.push(strt); 
      visited[strt] = 1;
      par[strt] = -1;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto child: adj[node]) {
          if(visited[child]) continue;
          visited[child] = 1;
          q.push(child);
          par[child] = node; 
          if(child == n) return true;
        }
      } 
      return false;
    } 
    
    void pathGen() {
      vector<int>ans;
      int node = n;
      while(node != 1) {
        ans.push_back(node);
        node = par[node];
      } 
      ans.push_back(node); 
      cout << ans.size() << '\n';
      reverse(ans.begin(), ans.end());
      for(auto i : ans) cout << i <<' ';
    }

};
//https://cses.fi/problemset/task/1667/

void solve() {
   int n, m; cin >> n >> m;
   BFS fun(n); 
   fun.input(m); 
   if(fun.bfs()) {
     fun.pathGen();
   } else cout << "IMPOSSIBLE";
}
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // test_case
  solve(),
      cout<<'\n';
  return 0;
}
