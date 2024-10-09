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
const int N = 9e5+7;
const int INF = INT64_MAX;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector<pair<int,int>> adj[N];
struct DIJKSTRA {
    int n, m;
    vector<int>distance, vis, par;
    
    DIJKSTRA (int n, int m){
      this->n = n, this->m = m;
      distance.resize(n + 5, INF); 
      vis.resize(n + 5, 0); par.resize(n + 5); 
      for(int i = 0; i <= n; i++) adj[i].clear();
    } 

    void getInput () {  
      for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
      }
    }  

    void run(int Start) {
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
       q.push({0, Start}); distance[Start] = 0;
       par[Start] = Start;
       while(!q.empty()) {
         int node = q.top().second, dist = q.top().first;
         q.pop();
         if(vis[node]) continue;
         vis[node] = 1;
        for(auto V: adj[node]) {
          int child = V.first, D = V.second;  
          if(distance[child] > distance[node] + D) {
            distance[child] = distance[node] + D;
            par[child] = node;
            q.push({distance[child], child});
          }
        }
      }
    }
    void pathprint(int node) {
      if(par[node] == node) return; // par of starting node is itself
      pathprint(par[node]);
      cout << node << ' ';
    }
    void printing() {  
      // change as problem required
      if(distance[n] == INF) cout << "Impossible";
      else cout << distance[n];
    }
}; 


void solve() {  
  print_case;
  int n, m; cin >> n>> m; 
  DIJKSTRA hs(n, m);
  hs.getInput();
  hs.run(1); 
  hs.printing();

}
// https://lightoj.com/problem/brush-5
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
  return EXIT_SUCCESS;
}
