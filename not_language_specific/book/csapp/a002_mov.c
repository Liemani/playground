void nothing(short s, int i, long long int ll) {
    (void)s;
    (void)i;
    (void)ll;
}

int main(void) {
    short s = 1;
    int i = 2;
    long long int ll = 0xffffffffffffffff;

    nothing(s, i, ll);

    return 0;
}
