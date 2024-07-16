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
int inv(int num, int mod) {
  return binex(num, mod - 2, mod);
}