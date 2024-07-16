#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
 
// using namespace boost::multiprecision;
 
// #define int cpp_int
#define int long long
#define ull unsigned long long
#define EPS 1e-9
 
#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)
 
#define print_case cout << "Case " << ++cas << ": "
#define mod (int) 1e9+7
const int N = 1e5+7;
const int INF = INT64_MAX;
using namespace std;
int a[4*N];
vector<int>sol;
void make_seg_tree(int node, int b, int e) {
  if(b==e) {
    a[node] = sol[b];
    return;
  }
  int l = node * 2, r = node * 2 + 1;
  int mid = b + e >> 1;
  make_seg_tree(l, b, mid);
  make_seg_tree(r, mid + 1, e);
  a[node] = a[l] + a[r];
}
void upd(int node, int b, int e, int ind, int value) {
  if(ind > e or ind < b) return;
  if(b == e and b == ind) {
    a [node] = value;
    return;
  }
  int l = node * 2, r =2 * node  + 1;
  int mid = (b + e) >> 1;
  upd(l, b, mid, ind, value);
  upd(r, mid+1, e, ind, value);
  a[node] = a[l] + a[r];
}
int cnt(int node, int b, int e, int i, int j) {
    if(j<b or i>e) return 0;
    if(i<=b and j>=e) return a[node];
    int l = node * 2, r = node * 2 + 1;
    int mid = b + e >> 1;
    return cnt(l, b, mid, i, j) + cnt(r, mid+1, e, i, j);
}
void solve() {
    int n, q; cin >> n >> q;
    sol.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin>>sol[i];
    make_seg_tree(1, 1, n);
    while(q--) {
      int typ; cin >> typ;
      if(typ == 1) {
          int ind, value; cin >> ind >> value;
          upd(1, 1, n, ind+1, value);
      }
      else {
         int i, j; cin >> i >> j;
         cout << cnt(1, 1, n, i+1, j)<<'\n';
      }
    }
   

}
 //https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
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