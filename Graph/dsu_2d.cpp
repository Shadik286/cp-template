#include <bits/stdc++.h>
 
#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)

using namespace std;

struct DSU { 
  // map<pair<int,int>, pair<int,int>>par; // slower but easy.
  vector<vector<pair<int,int>>>par; //way faster.
  // map<pair<int,int>, int>sz;
  vector<vector<int>>sz; 

  DSU (int n, int m) {
    sz.resize(n + 10, vector<int>(m + 10));
    par.resize(n + 10, vector<pair<int,int>>(m + 10));
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        // par[{i, j}] = {i, j}; 
        par[i][j] = {i, j};
        sz[i][j] = 0;
        // sz[{i, j}] = 0;
      }
    }
  }
  pair<int,int> find_par(pair<int,int>pp) {
    if(par[pp.first][pp.second] == pp) return pp;
    return par[pp.first][pp.second] = find_par(par[pp.first][pp.second]);
  } 
  void union_(pair<int,int>a, pair<int,int> b) {
    a = find_par(a), b = find_par(b); 
    if(a != b) {
      if(sz[a.first][a.second] < sz[b.first][b.second]) swap(a, b); 
      par[b.first][b.second] = a;
      sz[a.first][a.second] += sz[b.first][b.second];
    }
  }
}; 

//https://codeforces.com/contest/1985/problem/H1 
void solve() { 
  int n, m; cin >> n >> m;
  char adj[n + 1][m + 1];  
  DSU dsu(n, m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> adj[i][j]; 
      if(adj[i][j] == '#') dsu.sz[i][j] = 1;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(adj[i][j] == '#') {
        if(i + 1 <= n and adj[i + 1][j] == '#') dsu.union_({i, j}, {i + 1, j});
        if(i - 1 >= 1 and adj[i - 1][j] == '#') dsu.union_({i, j}, {i - 1, j});
        if(j + 1 <= m and adj[i][j + 1] == '#') dsu.union_({i, j}, {i, j + 1});
        if(j - 1 >= 1 and adj[i][j - 1] == '#') dsu.union_({i, j}, {i, j - 1});
      }
    }
  } 

  // for(int i = 1; i <= n; i++) {
  //   for(int j = 1; j <= m; j++) {
  //     cout << dsu.sz[{i, j}] << ' ';
  //   } cout << '\n';
  // }
  int ans = 0;
  for(int j = 1; j <= m; j++) {
    int cnt = 0; set<pair<int,int>>taken; 
    for(int i = 1; i <= n; i++) { 
      int add = 0;
      if(j - 1 >= 1) {
        pair<int,int> pp = dsu.find_par({i, j - 1});
        if(taken.find(pp) == taken.end()) {
          taken.insert(pp); add += dsu.sz[pp.first][pp.second];
        }
      } 
      if(j + 1 <= m) {
        pair<int,int> pp = dsu.find_par({i, j + 1});
        if(taken.find(pp) == taken.end()) {
          taken.insert(pp); add += dsu.sz[pp.first][pp.second];
        }
      }   
      if(adj[i][j] != '#') add++;
      else {
        pair<int,int> P = dsu.find_par({i, j});
        if(taken.find(P) == taken.end()) add+= dsu.sz[P.first][P.second], taken.insert(P);
      }
      // cout << j << ' ' << i << ' '<< add << '\n';
      cnt += add; 
      // cout << j << ' ' <<i << ' ' << cnt << '\n';
      
    } 
    ans = max(ans, cnt); 
  } 
  
  for(int i = 1; i <= n; i++) { 
    int cnt = 0; set<pair<int,int>>taken;
    for(int j = 1; j <= m; j++) {
      if(i - 1 >= 1) {
        pair<int,int> pp = dsu.find_par({i - 1, j});
        if(taken.count(pp) == 0) {
          taken.insert(pp); 
          cnt += dsu.sz[pp.first][pp.second];
        } 
      } 
      if(i + 1 <= n) {
        pair<int,int>pp = dsu.find_par({i + 1, j});
        if(taken.find(pp) == taken.end()) {
          taken.insert(pp); cnt += dsu.sz[pp.first][pp.second];
        }
      } 
      if(adj[i][j] != '#') cnt++;
      else {
        pair<int,int> p = dsu.find_par({i, j});
        if(taken.find(p) == taken.end()) {
          cnt += dsu.sz[p.first][p.second]; taken.insert(p);
        }
      }
      
    } ans = max(ans, cnt);
  }
  cout << ans;

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