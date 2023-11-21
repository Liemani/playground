long mult2(long, long);

void multstore(long x, long y, long* result) {
    long t = mult2(x, y);
    *result = t;
}
