
struct trie{

    struct node {
        node* childs[2];
        bool ends = false;
    }; 

    node* root;
    trie() {
        root = new node();
    } 

    void insert(int val) {
        node* cur = root; 
        for(int i = 30; i >= 0; i--) {
            int bt = val >> i & 1;
            if(cur->childs[bt] == NULL) {
                cur->childs[bt] = new node();
            } 
            cur = cur->childs[bt];
        }
        cur->ends = true;
    } 

    bool search(int val) {
        node* cur = root;
        for(int i = 30; i >= 0; i--) {
            int bt = val >> i & 1;
            if(cur->childs[bt] == NULL) {
                return false;
            }
            cur = cur -> childs[bt];
        }
        return cur->ends;
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
        for(int i = 30; i >= 0; i--) {
            int bt = val >> i & 1;
            cur = cur->childs[bt];
        }
        cur->ends = false;
    }

};

void solve() {

    trie* tr = new trie();

    tr->insert(1); 
    tr->insert(3);
    tr->insert(2);
    tr->del(1);
    cout << tr->search(2);

}
