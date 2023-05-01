int add_one(int x) {
    return x + 1;
}

int main(int argc, char** argv) {
    (void) argv;

    int x = argc;
    long y = argc;
    x = add_one(x);
    y = add_one(y);
    return x + y;
}
