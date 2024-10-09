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
struct SGMT { 
    vector<int>a, sol;
    int n;  
    // 1 indexed. 
    SGMT (int n) {
      this->n = n; 
      a.resize(4 * (n + 2)); sol.resize(n + 2);
    }
    
    void input() {
      for(int i = 1; i <= n; i++) cin >> sol[i];
    }
    int operate(int x, int y) {
      return x + y;
    }
    void make_seg_tree(int node, int bg, int en) {
      if(bg == en) {
        a[node] = sol[bg];
        return;
      }
      int mid = bg + en >> 1; 
      int left = node * 2, right = (node * 2) + 1; 
      make_seg_tree(left, bg, mid);
      make_seg_tree(right, mid + 1, en); 
      a[node] = operate(a[left], a[right]);
    } 
    void update(int node, int bg, int en, int ind, int value) {
      if(ind > en or ind < bg) return; 
      if(ind == en and en == bg) {
        sol[ind] = value, a[node] = value;
        return;
      } 
      int left = 2 * node, right = (2 * node) + 1; 
      int mid = bg + en >> 1;
      update(left, bg, mid, ind, value);
      update(right, mid + 1, en, ind, value); 
      a[node] = operate(a[left], a[right]);
    }  
    int gen_output(int node, int bg, int en, int left, int right) {
      if(left > en or right < bg) return 0;
      if(bg >= left and en <= right) {
        return a[node];
      } 
      int lft = 2 * node, rgt = (2 * node) + 1; 
      int mid = bg + en >> 1;
      int l = gen_output(lft, bg, mid, left, right);
      int r = gen_output(rgt, mid + 1, en, left, right);
      return operate(l, r);
    } 
    // problem requirments//////////// 
   

};
void solve() { 
  int n, q; cin >> n >> q;  
  SGMT seg_tree(n);
  // seg_tree.rcv_n(n);
  seg_tree.input(); 
  seg_tree.make_seg_tree(1, 1, n); 
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int i, v; cin >> i >> v; 
      seg_tree.update(1, 1, n, i + 1, v);
    } else {
      int l, r; cin >> l >> r;
      cout << seg_tree.gen_output(1, 1, n, l + 1, r) <<'\n';
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
  //test_case
  solve(),
      cout<<'\n';
  return EXIT_SUCCESS;
}
