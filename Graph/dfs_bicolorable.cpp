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
 
#define print_case cout << "Scenario #" << ++cas << ":\n"
#define mod (int) 1e9+7
const int N = 9e5+7;
const int INF = INT64_MAX;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector<int>adj[(int)(1e6)]; 
vector<int>visited((int)(1e6)), col((int)(1e6));
struct DFS { 
   int n, m;
   DFS(int n, int m) { 
    this->n = n; this->m = m; 
    for(int i = 0; i <= n + 2; i++) {
      adj[i].clear(); 
      visited[i] = 0; 
    }
   }    
   void takeInput() { 
    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a++, b++;
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

   bool bicolorable(int node, int color) {
    // UVA 10004 - Bicoloring 
    // true means bicolorable, Storing colors in visited array.
    visited[node] = color;
    bool ok = true;
    for(auto child: adj[node]) {
      if(visited[child] != 0) {
        if(visited[child] == visited[node]) return false;
      } else {
        ok &= bicolorable(child, 1 + (color == 1)); 
      }
    } 
    return ok;
   } 
   void printing() {
    for(int i = 1; i<= m; i++) cout << visited[i];
   }
  

};


void solve() { 
  print_case;
    int n, m; cin >> n >> m;
    DFS run(n, m);
    run.takeInput(); 
    for(int i = 1; i <= n; i++) {
      if(!visited[i]) {
        if(run.bicolorable(i, 1)) continue;
        return void(cout << "Suspicious bugs found!");
      }
    }
    cout << "No suspicious bugs found!";

    

}
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  test_case
  solve(),
      cout<<'\n';
  cout<<fixed<<setprecision(10);
  cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return EXIT_SUCCESS;
}