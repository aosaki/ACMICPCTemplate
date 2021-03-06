// Transforms the interval [x, y) in a.
void transform(int x, int y) {
  if ( x == y - 1) {
    return;
  }
  int l2 = ( y - x ) / 2;
  int z = x + l2;
  transform(x, z);
  transform(z, y);
  for (int i=x; i<z; i++) {
    int x1 = a[i];
    int x2 = a[i+l2];
    a[i] = (x1 - x2 + MOD) % MOD;
    a[i+l2] = (x1 + x2) % MOD;
  }
}
// Reverses the transform in
// the interval [x, y) in a.
void untransform(int x, int y) {
  if ( x == y - 1) {
    return;
  }
  int l2 = ( y - x ) / 2;
  int z = x + l2;
  for (int i=x; i<z; i++) {
    long long y1 = a[i];
    long long y2 = a[i+l2];
    // x1 - x2 = y1
    // x1 + x2 = y2
    // 2 * x1  = y1 + y2
    // 2 * x2  = y2 - y1

    // In order to solve those equations, we need to divide by 2
    // But we are performing operations modulo 1000000007
    // that needs us to find the modular multiplicative inverse of 2.
    // That is saved in the INV2 variable.

    a[i] = (int)( ((y1 + y2)*INV2) % MOD );
    a[i+l2] = (int)( ((y2 - y1 + MOD)*INV2) % MOD );
  }
  untransform(x, z);
  untransform(z, y);
}

