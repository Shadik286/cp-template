#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
 
// using namespace boost::multiprecision;
 
// #define int cpp_int 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define ull unsigned long long
#define EPS 1e-9
int cas = 0; 
using namespace __gnu_pbds;
 
#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)
 
#define print_case cout << "Case " << ++cas << ": "
#define mod (int) 1e9+7
const int N = 11000;
const int INF = INT64_MAX;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector<int>adj[N]; 
vector<int>visited(N), col(N); 
vector<int>dept (N);
struct DFS { 
   int n, m;
   DFS(int n, int m) { 
    this->n = n; this->m = m; 
    for(int i = 0; i <= n; i++) {
      adj[i].clear(); dept[i] = 0;
      visited[i] = 0; 
    }
   }    
   void takeInput() { 
    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      adj[a].push_back(b), adj[b].push_back(a);
    }
   }
   void dfs(int node) {
    if(visited[node]) return;
    visited[node] = 1;
    for(auto child: adj[node])  {
      dfs(child);
    }
   } 

   bool cycle_detect(int node, int parr = -1) {
    visited[node] = 1; 
    bool cycle = false;
    for(auto child: adj[node]) { 
      if(visited[child] and parr == child) continue;
      if(visited[child]) return true;
      cycle |= cycle_detect(child, node);
    }
    return cycle; //Returns True if cycle is found.
    // https://www.spoj.com/problems/PT07Y/en/
   } 
   

   
   

};


void solve() { 
  int n, m; cin >> n >> m;
  DFS run(n, m);   
  run.takeInput();
  bool ok = run.cycle_detect(1, -1);
  if(ok) return void(cout << "NO");
  for(int i = 1; i <= n; i++) { 
    if(!visited[i]) return void(cout << "NO");
  }
  cout << "YES";

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
  cout<<fixed<<setprecision(10);
  cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return EXIT_SUCCESS;
}