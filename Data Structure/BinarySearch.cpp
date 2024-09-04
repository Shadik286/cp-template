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

int calc(int x) {
  x *= (x + 1); 
  return x >>= 1;
}
int calc (int r, int l) {
  r = calc(r), l = calc(l - 1);
  return r - l;
}
bool check(int x, int l, int r) {
  int lft = calc(l, x), rt = calc(x + 1, r);
  return rt >= lft;
}
int binarysearch(int l, int r) {
  int bg = l, en = r, ans = -1;
  int mid = bg + en >> 1;
  while(bg <= en) {
    if(check(mid, l, r)) {
      ans = mid; en = mid - 1;
    } else bg = mid + 1;
    mid = en + bg >> 1;
  }
  return ans;
} 
//https://codeforces.com/contest/2009/problem/E
void solve() {
  int n, l; cin >> n >> l; 
  int mid = binarysearch(l, l + n); 
  // cout << mid << '\n';  
  // cout << l + n << '\n'; 
  n -= 1;
  // cout << calc(l + n, mid + 1) << '\n';
  int ans = calc(mid, l) - calc(l + n, mid + 1); ans = abs(ans); 
  // cout << ans << '\n';
  mid += 1;
  ans = min(ans, abs(calc(mid, l) - calc(l + n, mid + 1)));
  mid -= 2; 
  ans = min(ans, abs(calc(mid, l) - calc(l + n, mid + 1)));
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
  return 0;
}
