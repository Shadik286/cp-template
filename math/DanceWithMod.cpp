int binex(int a, int b, int m) {
  int ans = 1;
  while(b) {
    if(b & 1) {
      ans = (ans * 1LL * a) % m;
    }
    a = (a * 1LL * a) % m;
    b >>= 1;
  }
  return ans;
}
int inv(int num) {
  return binex(num, mod - 2, mod);
} 

struct modOP {
  int add(int a, int b) {
    int x = (mod + (a % mod) + (b % mod)) % mod; 
    return x;
  } 
  int multiply(int a, int b) {
    int x = ((a % mod) * (b % mod)) % mod;
    return x;
  } 
  int divide(int a, int b) {
    int INVb = inv(b); 
    int x = multiply(a, INVb);  
    return x;
  }
}modOP;
