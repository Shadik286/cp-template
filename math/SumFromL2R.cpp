int calc(int x) {
  x *= (x + 1); 
  return x >>= 1;
}
int calc (int r, int l) {
  r = calc(r), l = calc(l - 1);
  return r - l;
}
