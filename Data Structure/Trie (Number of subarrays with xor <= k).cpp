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


struct trie{ 

    int b = 31;
    struct node {
        node* childs[2];
        bool ends = false; 
        int cnt = 0;
    }; 

    node* root;
    trie() {
        root = new node();
    } 

    void insert(int val) {
        node* cur = root; 
        for(int i = b; i >= 0; i--) {
            int bt = val >> i & 1;
            if(cur->childs[bt] == NULL) {
                cur->childs[bt] = new node();
            } 
            cur = cur->childs[bt]; 
            cur->cnt++;
        }
        cur->ends = true;
    } 

    //Number of subarrays with xor < k
    int query(int x, int k) {
        node* cur = root;
        int ans = 0;
        for(int i = b; i >= 0; i--) {
            int bx = x >> i & 1;
            int bk = k >> i & 1;
            if(bk) {
                if(bx) {
                    if(cur->childs[1] != NULL) ans += cur->childs[1]->cnt;
                    if(cur->childs[0] != NULL) cur = cur->childs[0];
                    else break;
                } else {
                    if(cur->childs[0] != NULL) ans += cur->childs[0]->cnt;
                    if(cur->childs[1] != NULL) cur = cur->childs[1];
                    else break;
                }
            } else {
                if(cur->childs[bx] != NULL) cur = cur->childs[bx];
                else break;
            }
        }
        return ans;
    }
};
//https://www.spoj.com/problems/SUBXOR/
void solve() {

    trie* tr = new trie();
    tr->insert(0);
    int n, k; cin >> n >> k;
    vector<int>sol(n); for(auto &i: sol) cin >> i;
    int xr = 0; 
    int ans = 0;
    for(auto i: sol) {
        xr ^= i;        
        ans += tr->query(xr, k);
        tr->insert(xr); 
    }
    cout << ans;

}
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  test_case
  solve(),
      cout<<'\n';
  return 0;
}
