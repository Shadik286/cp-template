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

int inversion_count(vector<int> &a) {
  ordered_set<int>ost; 
  int cnt = 0;
  for(int i = 0; i < a.size(); i++) {
    int ind = ost.order_of_key(a[i]);  
    cnt += (ost.size() - ind);
    ost.insert(a[i]); 
    //cout << a[i] << ' ' << ind << '\n';
  } 
  return cnt;
}
//https://codeforces.com/contest/1983/problem/D

void solve() { 
    int n; cin >> n;
    vector<int>a(n), b(n); 
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i; 

    int dd = inversion_count(a) - inversion_count(b); 
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    // cout << dd << '\n';
    if(dd % 2 == 0 and a == b) cout << "Yes";
    else cout << "No";


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
  return EXIT_SUCCESS;
}