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


void prec() {}

struct Trie{
    struct node {
        node* childs[26]; 
        int lens[20] = {0};
        int cnt = 0; 
        int ends = 0;
    };
    node* root;
    Trie() {
        root = new node();
    }

    void insert(string s) {
        node* cur = root;
        for(int i = 0; i < s.size(); i++) {
            if(cur->childs[s[i] - '0'] == NULL) { 
                cur->childs[s[i] - '0'] = new node(); 
            }
            cur = cur->childs[s[i] - '0']; 
            cur->cnt++; 
            cur->lens[s.size()]++;
        } 
        cur->ends++; 
    }

    int search(string s) { 
        node* cur = root;
        for(int i = 0; i < s.size(); i++) {
            if(cur->childs[s[i] - '0'] == NULL) { 
                return 0;
            }
            cur = cur->childs[s[i] - '0'];
        } 
        return cur->cnt;
    }
    int query() {
        vector<char>vs(10); for(auto &i: vs) cin >> i;
        string s; cin >> s; 
        int len = s.size();
        int ans = 0;  
        node* cur = root; 
        int indx = -1, nms = 0; 
        for(int i = 0; i < len; i++) { 
            for(int ii =  0; ii < 10; ii++) {
                if(vs[ii] == s[i]) {
                    indx = ii; break;
                }
            }
            for(int ii = 0; ii < 10; ii++) {
                char ch = vs[ii];
                nms = (ii > indx);
                if(ii == indx) continue;
                for(int ln = 1; ln <= len - nms; ln++) {
                    if(cur->childs[ch - '0'] != NULL) {
                        ans += cur->childs[ch - '0']->lens[ln];
                    }
                }
            }
            if(cur->childs[s[i] - '0'] == NULL) break;
            cur = cur->childs[s[i] - '0'];   
            // ans += cur->ends;
        }  

        cur = root; 
        for(int i = 0; i < len - 1; i++) {
            if(cur->childs[s[i] - '0'] == NULL) break;
            cur = cur->childs[s[i] - '0'];   
            ans += cur->ends;
        }

        return ans;

    }

};
void solve() { 
    int n; cin >> n; 
    Trie *tr = new Trie();
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        tr->insert(s);
    }
    int q; cin >> q;
    while(q--) {
        cout << tr->query() << '\n';
    }
  
}
 
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
prec();
//   test_case
  solve();
  return 0;
}