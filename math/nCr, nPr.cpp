int fact[N], invfact[N]; 
int M = (int)(1e9+7);
int power(int base, int pwr, int mod) {
    int ans = 1;
    while(pwr) {
        if(pwr&1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        pwr /= 2;
    }
    return ans;
}

void factorial() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    for(int i = 0; i < N; i++) {
        invfact[i] = power(fact[i], M - 2, M) % M;
    }
} 
int ncr(int n, int r) {
    if(n < r) return 0;
    return (fact[n] * invfact[r] % M)*invfact[n - r] % M;
} 
int npr(int n, int r) {
    if(n < r) return 0;
    return fact[n]*invfact[n - r]%M;
}
