struct FenwickTree {
    vector<int>fen;
    int n;
    FenwickTree(int n) {
      fen.resize(n + 1, 0); this->n = n;
    }
    FenwickTree(vector<int>&a) {
      this->n = a.size() + 1; 
      fen.resize(n + 2, 0);
      for(int i = 1; i <= a.size(); i++) {
        add(i, a[i - 1]);
      }
    }
    void add(int i, int x) {
      while(i <= n) {
        fen[i] += x; 
        i += (i & (-i));
      }
    }
    int sum(int ind) {
      int sm = 0;
      while(ind > 0) {
        sm += fen[ind];
        ind -= (ind & (-ind));
      }
      return sm;
    }
    int sum(int l, int r) {
      return sum(r) - sum(l - 1);
    }
};
