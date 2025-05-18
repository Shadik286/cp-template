struct trie{ 

    int bt = 31;
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
        for(int i = bt; i >= 0; i--) {
            int bt = val >> i & 1;
            if(cur->childs[bt] == NULL) {
                cur->childs[bt] = new node();
            } 
            cur = cur->childs[bt]; 
            cur->cnt++;
        }
        cur->ends = true;
    } 

    bool search(int val) {
        node* cur = root;
        for(int i = bt; i >= 0; i--) {
            int bt = val >> i & 1;
            if(cur->childs[bt] == NULL) {
                return false;
            }
            cur = cur -> childs[bt];
        }
        return cur->ends;
    } 

    int get_max(int x) { // returns maximum of val ^ x
        node* cur = root;
        int ans = 0;
        for (int i = bt; i >= 0; i--) {
            int k = x >> i & 1; 
            // Min er laghi !k er jaygay k and k er jaygay !k
            if (cur -> childs[!k] and cur->childs[!k]->cnt) cur = cur -> childs[!k], ans <<= 1, ans++;
            else cur = cur -> childs[k], ans <<= 1;

            // For min
            // if (cur -> childs[k] and cur.childs[k]->cnt) cur = cur -> childs[k], ans <<= 1;
            // else cur = cur -> childs[!k], ans <<= 1, ans++;

        }
        return ans;
    }
    int get_min(int x) { // returns minimum of val ^ x
        node* cur = root;
        int ans = 0;
        for (int i = bt; i >= 0; i--) {
            int k = x >> i & 1;
            if (cur -> childs[k]) cur = cur -> childs[k], ans <<= 1;
            else cur = cur -> childs[!k], ans <<= 1, ans++;
        }
        return ans;
    }

    void deleteTrie() {
        deleteTrie(root);
    }
    // Delete whole trie
    void deleteTrie(node* cur) {
        for(int i = 0; i < 2; i++) {
            if(cur->childs[i] != NULL) {
                deleteTrie(cur->childs[i]);
            }
        }
        delete cur;
    }

    // Deletes a single element (Not Completed, the nodes are still there).
    void del(int val) {
        node* cur = root;
        for(int i = bt; i >= 0; i--) {
            int bt = val >> i & 1;
            cur = cur->childs[bt]; 
            cur->cnt--;
        }
        cur->ends = false;
    }

};

void solve() {

    trie* tr = new trie();
    tr->insert(0);
    int n; cin >> n; 
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        int t; cin >> t;
        if(c == '+') tr->insert(t);
        else if(c == '-') {
            tr->del(t);
        } else {
            cout << tr->get_max(t) << '\n';
        }
    }

}
