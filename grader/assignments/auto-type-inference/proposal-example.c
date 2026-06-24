// Example program demonstrating auto type inference in Selfie.
uint64_t factorial(uint64_t n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

uint64_t main() {
    auto n    = 10;            // uint64_t  -- integer literal
    auto res  = factorial(n);  // uint64_t  -- procedure return type
    auto flag = (res > 0);     // uint64_t  -- comparison (0/1)
    auto msg  = "Selfie";      // uint64_t* -- string literal
    auto p    = malloc(8);     // uint64_t* -- malloc result
    *p = res;
    auto v    = *p;            // uint64_t  -- dereference

    if (res == 3628800)
        if (flag == 1)
            if (v == 3628800)
                return 0;
    return 1;
}
