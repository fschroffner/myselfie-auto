// Test: pointer arithmetic preserves uint64_t* through auto
uint64_t main() {
    auto p = malloc(8);
    *p = 10;
    auto q = p + 1;
    auto r = q - 1;
    auto x = *r;
    if (x == 10)
        return 0;
    return 1;
}
