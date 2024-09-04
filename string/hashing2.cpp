#include <bits/stdc++.h>

#define test_case \
  int t;          \
  cin >> t;       \
  while (t--)
 
#define print_case cout << "Case " << ++cas << ": "
using namespace std;

const int N = 1e6 + 9;

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
  }
}

pair<int, int> rightshift(pair<int,int>a, int len) {
  int t1 = 1LL * a.first * pw[len].first % MOD1;
  int t2 = 1LL * a.second * pw[len].second % MOD2; 
  return {t1, t2};
} // to add we must place 2nd word after first so
  // rightshifting the 2nd word so that we can place 
  // first word to the left.

pair<int, int> concat(pair<int,int>a, pair<int,int>b, int len) {
  pair<int, int> rightshiftedB = rightshift(b, len); 
  pair<int, int> pp;
  pp.first = (1LL * a.first + rightshiftedB.first) % MOD1;
  pp.second = (1LL * a.second + rightshiftedB.second) % MOD2;
  return pp;
} // adding to string sha + dik = shadik


struct Hashing {
  int n;
  string s; // 0 - indexed
  vector<pair<int, int>> hs; // 1 - indexed
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = _s;
    hs.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
      p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
      hs.push_back(p);
    }
  } 
  pair<int, int> get_hash() {
    return get_hash(1, n);
  }
  pair<int, int> get_hash(int l, int r) { // 1 - indexed
    assert(1 <= l && l <= r && r <= n);
    pair<int, int> ans;
    ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
    ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
    return ans;
  }  
};

void solve() { 
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string cmp1 = "", aa = "", bb = ""; 
    string cmp2 = "";
    for(int i = 0; i < m; i++) {
      aa.push_back('0'), bb.push_back('1');
    }
    while(cmp1.size() + m + m <= n) {
      cmp1 += aa; cmp1 += bb; 
      cmp2 += bb; cmp2 += aa;
    } 
    if(cmp1.size() < n and cmp1.size()) cmp1 += aa, cmp2 += bb; 
    if(!cmp1.size() and cmp1.size() < n) {
      if(s[0] == '1') cmp1 += bb, cmp2 += bb;
      else cmp1 += aa, cmp2 += aa;
    } 
    Hashing compare(cmp1); 
    pair<int,int> CMP = compare.get_hash(); 
    Hashing compare2(cmp2);
    pair<int,int>CMP2 = compare2.get_hash(); 
    // cout << cmp1 << '\n';
    // cout << CMP.first << ' ' << CMP.second << '\n';
    Hashing frwdS(s);
    reverse(s.begin(), s.end());
    Hashing bckS(s);  
    int lst = n; 
    for(int i = 1; i < n; i++) {
      pair<int,int>fst = frwdS.get_hash(i + 1, n); 
      // cout << fst.first << ' ' <<fst.second << '\n';
      pair<int, int> last = bckS.get_hash(lst--, n);
      pair<int,int>tot = concat(fst, last, n - i);
      if(tot.first == CMP.first and tot.second == CMP.second) {
        return void(cout << i);
      } 
      if(tot.first == CMP2.first and tot.second == CMP2.second) {
        return void(cout << i);
      }
    }  
    cout << -1;
}
//https://codeforces.com/contest/1979/problem/D
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
prec();
  test_case 
  solve(),
      cout<<'\n';
  cout<<fixed<<setprecision(10);
  cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return EXIT_SUCCESS;
}
