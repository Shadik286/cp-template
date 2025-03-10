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
#define mod (int) 998244353
const int N = 9e5+7;
const int INF = INT64_MAX;
using namespace std;


void prec() {} 
struct Trie{
    struct node {
        node* childs[26];
        int cnt = 0; 
        bool ends = 0;
    };
    node* root;
    Trie() {
        root = new node();
    }

    void insert(string s) {
        node* cur = root;
        for(int i = 0; i < s.size(); i++) {
            if(cur->childs[s[i] - 'a'] == NULL) { 
                cur->childs[s[i] - 'a'] = new node(); 
            }
            cur = cur->childs[s[i] - 'a']; 
            cur->cnt++;
        } 
        cur->ends = true; 
    }

    int search(string s) { 
        node* cur = root;
        for(int i = 0; i < s.size(); i++) {
            if(cur->childs[s[i] - 'a'] == NULL) { 
                return 0;
            }
            cur = cur->childs[s[i] - 'a'];
        } 
        return cur->cnt;
        //to check if s is in the trie return cur->ends;
    }

};

void solve() { 
    int n, q; cin >> n >> q;
    Trie* trie = new Trie();
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        trie->insert(s);
    }
    while(q--) {
        string s; cin >> s; 
        cout << trie->search(s)<<'\n';
    }
    
}
//https://www.spoj.com/problems/ADAINDEX/
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
prec();
//   test_case
  solve(),
      cout<<'\n';
  return 0;
}
