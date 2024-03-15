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

struct DSU { 
  vector<int>par, sz;
  void rcv_n(int n) {
    par.resize(n + 10), sz.resize(n + 10);
  }
  void build_dsu(int v) {
    par[v] = v; sz[v] = 1;
  }  
  int find_par(int v) {
    if(par[v] == v) return v;
    return par[v] = find_par(par[v]);
  } 
  void union_(int a, int b) {
    a = find_par(a), b = find_par(b); 
    if(a != b) {
      if(a > b) swap(a, b); 
      par[b] = a;
      sz[a] += sz[b];
    }
  }

} dsu;

void solve() { 
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t; 
  dsu.rcv_n(n);
  for(int i = 0; i < n; i++) dsu.build_dsu(i);
  map<int, string>mp, mp2;
  for(int i = 0; i < n; i++) {
    if(i + k < n) dsu.union_(i, i + k);
    if(i + k + 1 < n) dsu.union_(i, i + k + 1);
  }
  for(int i = 0; i < n; i++) {
    int ind = dsu.find_par(i);
    mp[ind].push_back(s[i]); 
    mp2[ind].push_back(t[i]);
  } 
  //for(auto i : mp) cout <<i.first << ' ' <<i.second << '\n'; 
  for(auto i : mp) {
    string a = i.second, b = mp2[i.first];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    if(a != b) return void(cout << "NO");
  }
  cout << "Yes";

}
 // https://codeforces.com/contest/1800/problem/E2
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