// Test: auto with a malloc result infers uint64_t*
uint64_t main() {
    auto p = malloc(8);
    *p = 10;
    auto x = *p;
    if (x == 10)
        return 0;
    return 1;
}
